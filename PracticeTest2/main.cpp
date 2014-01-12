#include <iostream>
#include "soundex.h"

using namespace std;

//char lookup[] = "bfpv1cgjkqsxz2dt3l4mn5r6";

int main(){

  //cout << find_digit('b',lookup) << endl;
  //cout << find_digit('k',lookup) << endl;
  typedef char Soundex[5];
  Soundex soundex1,soundex2,soundex3;
  encode("Jackson", soundex1);
  cout << "Jackson is encoded as " << soundex1 << endl;
  encode("Washington", soundex2);
  cout << "Washington is encoded as " << soundex2 << endl;
  encode("Lee", soundex3);
  cout << "Lee is encoded as " << soundex3 << endl << endl;

  cout << compare("S250","S255") << endl;
  cout << compare("S250", "S250") << endl << endl;

  cout << count("Leeson", "Linnings, Leasonne, Lesson and Lemon.") << endl;

  return 0;


}
