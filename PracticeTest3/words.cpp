#include <cstring>
#include <cctype>
#include <iostream>

using namespace std;

void reverse(const char* string1, char* string2){

  int n = strlen(string1);
  for(int i = n; i >0; i--){
    *string2 = string1[i-1];
    ++string2;
  }
  string2[n] = '\0';
}

int compare(const char* string1, const char* string2){
  
  //cout << "string1: " << string1 << " " << endl;
  //cout << "string2: " << string2 << " " << endl;

  if(*string1 == '\0' && *string2 == '\0')
    return 1;

  if(!isalpha(*string1)){
    if(*string1 != '\0')
      compare(++string1, string2); 
    else{


    }
      
  }
    
  if(!isalpha(*string2)){
    if(*string2 != '\0')
      compare(string1,++string2);
    else{


    }
  }

  return(tolower(*string1) == tolower(*string2)) ? compare(++string1,++string2) : 0;
      
  
}
