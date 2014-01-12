#include <iostream>

#include "words.h"

using namespace std;

int main(){

  char reversed[9];
  reverse("lairepmi", reversed);

  cout << reversed;

  cout << compare("This and that", "this, and THAT!") << endl;

  //  cout << compare("these are not the SAME", "these are the SAME") << endl;

 return 0;

}
