/* You are pre-supplied with the functions below. Add your own 
   function prototypes to the end of this file. */

/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);

bool find_marker(char ch, char** maze, int height, int width, int& row, int& column);

bool valid_solution(const char* path, char** maze, int height, int width);

void make_move(char ch, int& row, int&column);

bool invalid_character(char ch);

bool at_hedge(char ch);

bool out_of_bounds(int height, int width, int row, int column);

const char* find_path(char** maze, int height, int width, char start, char end);

bool valid_path(char** maze, int height, int width, int row, int column, char direction);

bool path_helper(char **map, int height, int width, int row, int col, char start, char dest, char* dir);

bool valid_square(char square);

bool valid_col(int col, int width);
