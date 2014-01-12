#include <iostream>
#include <string>
#include "correct.h"

using namespace std;

/* You are supplied with two helper functions */

/* converts a character into a binary string representation */
//void ascii_to_binary(char ch, char *binary);

/* converts a binary string representation into a character */
//char binary_to_ascii(char *binary);

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1) 
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}


char binary_to_ascii(const char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

/* now add your own functions here */

void text_to_binary(const char * str, char * binary){
  if(*str == '\0')
    *binary = '\0';
  else{
    ascii_to_binary(*str,binary);
    text_to_binary(++str,(binary+8));
    }
}

void binary_to_text(const char* str, char * text){
  
  if(*str == '\0')
    *text = '\0';
  else{
    *text = binary_to_ascii(str);
    binary_to_text((str+8),++text);
  }
}

void add_error_correction(const char* str, char* corrected){

  if(*str == '\0')
    *corrected = '\0';
  else{
    char ch1 = parity(str[0],str[1],str[3]);
    char ch2 = parity(str[0],str[2],str[3]);
    char ch3 = parity(str[1],str[2],str[3]); 

    corrected[0] = ch1;
    corrected[1] = ch2;
    corrected[2] = str[0];
    corrected[3] = ch3;
    corrected[4] = str[1];    
    corrected[5] = str[2];    
    corrected[6] = str[3];
    
    add_error_correction(str+4,corrected+7);
  }

}

int decode(const char* str, char* decoded){

  return decode(str,decoded,0);

}

int decode(const char* str, char* decoded, int output){

  if(*str == '\0'){
    *decoded = '\0';
    return output;
  }
  else{
    char ch1 = parity(str[3],str[4],str[5],str[6]);
    char ch2 = parity(str[1],str[2],str[5],str[6]);
    char ch3 = parity(str[0],str[2],str[4],str[6]);     

    decoded[0] = str[2];
    decoded[1] = str[4];
    decoded[2] = str[5];
    decoded[3] = str[6];
    
    // Check whether there are any errors
    if(((ch1-'0')+(ch2-'0')+(ch3-'0')) > 0){
      
      cout << ch1 << " "  << ch2 << " " << ch3 << endl;

      output += 1;

      // Convert binary to decimal;
      int decimal = ((ch1-'0')*4)+((ch2-'0')*2)+((ch3-'0')*1);
      
      if(decimal == 3 || decimal == 5 || decimal == 6 || decimal == 7){
	// correct(str,decoded,decimal);

	char bit;
	
	if(str[decimal-1] == 0)
	  bit = '1';
	else
	  bit = '0';

	switch(decimal){
	case 3:
	  decoded[0] = bit;
	  break;
	case 5:
	  decoded[1] = bit;
	  break;
	case 6:
	  decoded[2] = bit;
	  break;
	case 7:
	  decoded[3] = bit;
	  break;

	}
      }
    }
    output = decode(str+7,&(decoded[0])+4, output);
  }

  return output;

}

char parity(char ch1, char ch2, char ch3){

  return (((ch1-'0')+(ch2-'0')+(ch3-'0'))%2 == 0) ? '0' : '1';

}

char parity(char ch1, char ch2, char ch3, char ch4){

  return (((ch1-'0')+(ch2-'0')+(ch3-'0')+(ch4-'0'))%2 == 0) ? '0' : '1';

}


void correct(const char * str, char*& decoded, int error){

  char bit;

  if(str[error-1] == 0)
    bit = '1';
  else
    bit = '0';

  switch(error){
  case 3:
    decoded[0] = bit;
    break;
  case 5:
    decoded[1] = bit;
    break;
  case 6:
    decoded[2] = bit;
    break;
  case 7:
    decoded[3] = bit;
    break;

  }
}
