#include <ostream>

using namespace std;

int encode_character(char message, char * encode);

char* get_cell(char input);

char convert(char input);

void encode(const char* plaintext, char* encode);

void print_braille(const char* plaintext, ostream& output);
