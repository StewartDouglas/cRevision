#include <iostream>
#include "substring.h"

using namespace std;

int main(){
  
  if(is_prefix("ste","stewart")){
     cout << "ste is a prefix of stewart" << endl;
  }
  else{
  cout << "ste is not a prefix of stewart";
  }

  if(is_prefix("indent","indentation")){
     cout << "indent is a prefix of indentation" << endl;
  }
  else{
  cout << "ste is not a prefix of stewart";
  }

  if(is_prefix("c","c")){
     cout << "c is a prefix of c" << endl;
  }
  else{
  cout << "ste is not a prefix of stewart";
  }

  if(is_prefix("ste","zxcasdasc")){
     cout << "ste is a prefix of stewart" << endl;
  }
  else{
  cout << "ste is not a prefix of zxcasdasc";
  }
  cout << endl;

  //  cout << substring_position("te","stewart") << endl;
  cout << substring_position("this", "this is a simple exercise",0) << endl;
  cout << substring_position("is", "this is a simple exercise",0) << endl;
  cout << substring_position("is a", "this is a simple exercise",0) << endl;
  cout << substring_position("is an", "this is a simple exercise",0) << endl;
  cout << substring_position("exercise", "this is a simple exercise",0) << endl;
  cout << substring_position("simple exercise", "this is a simple",0) << endl;
  cout << substring_position("", "this is a simple exercise",0) << endl;
  cout << substring_position("", "",0) << endl;


  cout << substring_position2("this", "this is a simple exercise",0) << endl;
  cout << substring_position2("is", "this is a simple exercise",0) << endl;
  cout << substring_position2("is a", "this is a simple exercise",0) << endl;
  cout << substring_position2("is an", "this is a simple exercise",0) << endl;
  cout << substring_position2("exercise", "this is a simple exercise",0) << endl;
  cout << substring_position2("simple exercise", "this is a simple",0) << endl;
  cout << substring_position2("", "this is a simple exercise",0) << endl;
  cout << substring_position2("", "",0) << endl;


  return 0;

}
