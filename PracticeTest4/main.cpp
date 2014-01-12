#include <iostream>
#include "braille.h"

using namespace std;

int main(){

 char braille[20];
 int size;
 size = encode_character('Z', braille);

 cout << braille << endl;
 cout << size << endl;

 char braille1[100];
 encode("Hello!", braille1);

 cout << braille1 << endl;

 cout << endl;
 
 print_braille("Hello!",cout);

 return 0;

}

