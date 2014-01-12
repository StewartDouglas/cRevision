#include <cctype>
#include <iostream>
#include <cstring>
#include "soundex.h"

using namespace std;

char lookup[] = "bfpv1cgjkqsxz2dt3l4mn5r6";

void encode(const char* surname, char* soundex){

  char ch, prev_ch;
  int count = 1;

  soundex[0] = toupper(*surname);
  ++surname;
  
  while(*surname != '\0'){
    //cout << *surname;
    ch = find_digit(*surname,lookup);
    //cout << " " << ch << endl;
    if(ch == '0' || (ch == prev_ch && count > 1)){
      ++surname;
    }
    else{
      soundex[count] = ch;
      ++count;
      ++surname;
      prev_ch = ch;
    }
  }
  for(int n = count; n < 4; n++)
    soundex[n] = '0';
  soundex[4] = '\0';

}

char find_digit(char input, char* lookup_position){
  char count = lookup_position[0];
  while(count != '\0'){
    if(input == count){
      while(!isdigit(count)){
	count = *(++lookup_position);
	//++lookup_position;
      }
      return count;
    }
    count = *(++lookup_position);
    //++lookup_position;
  }
  // Character not found.
  return '0';
}

int compare(const char* string1, const char* string2){

  if(*string1 == '\0' && *string2 == '\0')
    return 1;

  return(*string1 == *string2) ? compare(++string1,++string2) : 0;
}

int count(const char* string1, const char* string2){

  int count = 0;

  char* pch; 
  pch = strtok(const_cast<char*>(string2), " ,.");

  while(pch != NULL){
    if(compare(string1,pch))
      count++;
    pch = strtok(NULL, " ,.");
  }
  return count;
}
