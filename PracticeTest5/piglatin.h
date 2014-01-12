#include <fstream>
#include <iostream>

using namespace std;

void translateStream(istream& input, ostream& output);

void translateWord(const char* input, char* translated);

int findFirstVowel(const char* string);

bool vowel(char ch);
