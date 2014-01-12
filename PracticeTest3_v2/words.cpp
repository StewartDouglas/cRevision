#include <iostream>
#include <cstring>
#include "words.h"

using namespace std;

void reverse(const char* input, char* output){
  int length = strlen(input);
  for(int n = length; n > 0; n--){
    *output = input[n-1];
    ++output;
  }
  
  *output = '\0';
}

int compare(const char* string1, const char* string2){

  // BASE CASE
  if(*string1 == '\0' && *string2 == '\0')
    return true;

  // RECURSIVE CALL
  else{

    if(*string1 == '\0'){
      if(isalnum(*string2)){ 
	return false;
      }
         else
	   return compare(string1,++string2);
    }

    else if(*string2 == '\0'){
      if(isalnum(*string1)){
	   return false;
         }
         else
	   return compare(++string1,string2);
    }

    else if(!isalnum(*string1) && isalnum(*string2))
	return compare(++string1,string2);

    else if(isalnum(*string1) && !isalnum(*string2))
	 return compare(string1,++string2);

    else if(!isalnum(*string1) && !isalnum(*string2)){
      return compare(++string1,++string2);

    }

    else if(isalnum(*string1) && isalnum(*string2)){

      if(tolower(*string1) != tolower(*string2)){
	    return false;
      }
	 else
	   return compare(++string1,++string2);
	 
       }
  }

}


int palindrome(const char * string){
  
  int size = strlen(string);

  char output[size];

  if(size == 1 || size == 0)
    return 1;
  if(size == 2){
    if(isalpha(string[0]) && isalpha(string[1]))
      return (tolower(string[0]) == tolower(string[1])) ? 1 : 0;
    else
      return (string[0] == string[1]) ? 1 : 0;
  }

  if(isalpha(string[0]) && isalpha(string[size-1])){
    if(tolower(string[0]) == tolower(string[size-1])){
	get_sublist(string,1,size-2,output);
	return palindrome(output);
      }
    else {
       return 0;
      }
  }
  else if(!isalpha(string[0]) && isalpha(string[size-1])){
	return palindrome(++string);
      }

  else if(isalpha(string[0]) && !isalpha(string[size-1])){
	get_sublist(string,0,size-2,output);
	return palindrome(output);
      }

    else{
	get_sublist(string,1,size-2,output);
	return palindrome(output);
      }  
}

void get_sublist(const char * input, int start, int end, char* output){

  if(start == end)
    *output = input[start];
  else{
    for(int n = start; n <= end; ++n){
      *output = input[n];
      ++output;
    }
  }

  *output = '\0';


}


int anagram(const char* string1, const char* string2){

  int size = strlen(string2);
  char anagram[size+1];
  strcpy(anagram,string2);
  //char* beginning = &anagram[0];


  while(*string1 != '\0'){

    if(isalpha(*string1)){
      for(int i = 0; anagram[i] != '\0';){
	i++;
	if(tolower(*string1) == tolower(anagram[i])){
	  anagram[i] = ' '; 
	}
	else if(anagram[i] == '\0')
	  return 0;
      }
    }
    ++string1;
  }
    return 1;
}



