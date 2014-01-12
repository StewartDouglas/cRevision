#include <iostream>
#include <cstring>

using namespace std;

bool is_prefix(const char* string1, const char* string2){

  if(*string1 == '\0')
    return true;
  
  return(*string1 == *string2) ? is_prefix(++string1,++string2) : false;

}


int substring_position(const char* string1, const char* string2, int count){

  if(*string2 == '\0' && *string1 != '\0')
    return -1;

  if(is_prefix(string1,string2)){
      return count;
    }
  else{
      ++count;
      substring_position(string1,++string2,count);
  }
}

/*
int substring_position2(const char* string1, const char* string2, int count){
  return(strstr(string2,string1) != NULL) ? substring_position2(string1,++string2,++count) : count;

}
*/
