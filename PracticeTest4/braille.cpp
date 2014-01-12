#include <iostream>
#include <map>
#include <cctype>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "braille.h"

using namespace std;

char lookup[] = "..0..00,.0....;.00...-..0..0!.00.0.?.00..0(.00.00).00.00a0.....b00....c0..0..d0..00.e0...0.f'00.0..'g00.00.h00..0.i.0.0..j.0.00.k0.0...l000...m0.00..n0.000.o0.0.0.p0000..q00000.r000.0.s.000..t.0000.u0.0..0v000..0w.0.000x0.00.0y0.0000z0.0.00";

int encode_character(char message, char * encode){

  char* ch;
  char caps[] = ".....0";
  char num[] = "..0000";
  char* num_ptr = num; 
  char* caps_ptr = caps;
  bool flag = false;
  ch = get_cell(message);

  // Check whether the character is valid
  if(ch != NULL){
    // Check whether the character is a letter
    if(isalpha(message)){
      if(isupper(message)){
	while(*caps_ptr != '\0'){
	  *encode = *caps_ptr;
	  ++caps_ptr;
	  ++encode;
	}
	flag = true;
      }
    }

    // Check whether the character is a digit
    if(isdigit(message)){
 	while(*num_ptr != '\0'){
	  *encode = *num_ptr;
	  ++num_ptr;
	  ++encode;
	}
	flag = true;     
    }

      while(!isalpha(*ch)){
	*encode = *ch;
	++encode;
	++ch;
      }
  }

  // Check whether the character is punctuation
  if(ispunct(message)){
    for(int i = 0; i<6;i++){
      *encode = *ch;
      ++encode;
      ++ch;
    }
  }

  *encode = '\0';
  if(flag) return 12;

  return 6;

}


char* get_cell(char input){
  
  if(isdigit(input))
    input = convert(input);
  else
    input = tolower(input);

  char * ptr = lookup;
  while(*ptr != '\0'){
    if(*ptr == input)
      return ++ptr;
    else
      ++ptr;
  }

  return NULL;

}

char convert(char input){

  switch(input){
  case '0':
    return 'j';
    break;
  case '1':
    return 'a';
    break;
  case '2':
    return 'b';
    break;    
  case '3':
    return 'c';
    break;  
  case '4':
    return 'd';
    break;  
  case '5':
    return 'e';
    break;  
  case '6':
    return 'f';
    break;  
  case '7':
    return 'g';
    break;  
  case '8':
    return 'h';
    break;  
  case '9':
    return 'i';
    break;
  default:
    return 'z';
  }

}

void encode(const char* plaintext, char* output){

  int size = 0;

  if(*plaintext == '\0')
    *output = '\0';
  else{
    size = encode_character(*plaintext,output);
    encode(++plaintext,(output+size));     
  }


}


void print_braille(const char* plaintext, ostream& output){

  int size = strlen(plaintext)*6;
  char temp[20];
  char out[512];  
  encode(plaintext,out);

  if(encode_character(*plaintext,temp)==12)
    size += 6;


  for(int i = 0; i < 3; i++){
    cout << " ";
    for(int j = 0; j<(size/6);j++){
      output << out[(j*6)+i] << out[(j*6)+3+i] << " "; 
    }
    output << endl;
  }
 
  if(encode_character(*plaintext,temp)==12)
    output << "    ";
  

  output << setiosflags (ios::left );

  while(*plaintext != '\0'){
    
    output.width(3);
    output << *plaintext;
    ++plaintext;
  }

  output << endl;

}
