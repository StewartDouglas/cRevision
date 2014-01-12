#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>

#include "piglatin.h"

using namespace std;


// Recursive solution
void translateStream(ifstream& input, ostream& output){
  
  char word[64];
  char translation[64];

  if(input.eof())
    output << '\0';
  else {
    input >> word;
    if(isalnum(*word)){
      translateWord(word,translation);
    }
    output << translation << " ";
    translateStream(input,output);
  }
}

// Iterative solution
/*
void translateStream(ifstream& input, ostream& output){

  char word[64];
  char translation[64];

  while(input != '\0'){
    input >> word;
    translateWord(word,translation);
    output << " ";
    output << translation;
  }
}
*/

void translateWord(const char* input, char* translated){

  const char* way = "way";
  const char* ay = "ay";
  const char* add;
  bool upperFlag = isupper(*input);

  // Get position of the first vowel
  int vowel = findFirstVowel(input);

  // The word begins with a vowel, or contains no vowels, but does not begin 
  // with a digit
  if((vowel == 0 || vowel == -1) && !isdigit(*input)){

    while(*input != '\0'){
      *translated = *input;
      ++translated;
      ++input;
    }

    if(vowel == 0) 
      add = way;
    else
      add = ay;
    
    while(*add != '\0'){
      *translated = *add;
      ++translated;
      ++add;
    }
  }

  input = &input[0];

  // The word does not begin with a vowel, but it contains a vowel
  if(vowel > 0 && !isdigit(*input)){

    for(int i = vowel; input[i] != '\0'; i++){
      if(upperFlag && i == vowel)
	*translated = toupper(input[i]);
      else
	*translated = input[i];
      ++translated;
    }

    for(int i = 0; i < vowel; i++){
      *translated = tolower(input[i]);
      ++translated;
    }

    while(*ay != '\0'){
      *translated = *ay;
      ++translated;
      ++ay;
    }

  }
  
  input = &input[0];

  // The word begins with a digit
  if(isdigit(input[0])){
    while(*input != '\0'){
      *translated = *input;
      ++translated;
      ++input;
    }
  }
  
  *translated = '\0';

}


int findFirstVowel(const char* string){

  int count = 0;
  
  while(*string != '\0'){
    if(vowel(*string) && !(*string == 'y' && count == 0))
      return count;
    else{
      ++count;
      ++string;
    }
  }

  return -1;

}

bool vowel(char ch){
  
  ch = tolower(ch);

  return(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||ch == 'y');
    
}


void translateStream(istream& inputStream, ostream& outputStream){

  char input[65], output[65];
  while(inputStream >> input){
    translateWord(input,output);
    outputStream << output;
    outputStream << " ";
  }
}
























// *************** Ash's work ******************************
/*
void getWord(std::istream &in, char *word){
  char c;
  int position = 0;
  while (in >> std::noskipws >> c){
    if (isalnum(c))
      word[position++] = c;
    else {
      in.putback(c);
      break;
    }
  }
  word[position] = '\0';
}

void passStreamUntilWord(std::istream &in, std::ostream &out){
  char c;
  while (in >> std::noskipws >> c){
    if (!isalnum(c))
      out << c;
    else {
      in.putback(c);
      return;
    }
  }
}

void translateStream(std::istream &in, std::ostream &out){
  char word[65];
  char pigLatin[65];

  passStreamUntilWord(in, out);
  getWord(in, word);
  translateWord(word, pigLatin);
  out << pigLatin;

  char c;
  if (in >> std::noskipws >> c){
    in.putback(c);
    translateStream(in, out);
  }
}
*/
