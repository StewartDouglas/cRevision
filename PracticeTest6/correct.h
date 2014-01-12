#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(const char *binary);
void text_to_binary(const char * str, char * binary);
void binary_to_text(const char * str, char * text);
void add_error_correction(const char* str, char* corrected);
char parity(char ch1, char ch2, char ch3);
char parity(char ch1, char ch2, char ch3, char ch4);
int decode(const char* str, char* decoded);
int decode(const char* str, char* decoded, int output);
void correct(const char * str, char*& decoded, int error);

#endif
