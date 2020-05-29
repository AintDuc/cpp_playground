#ifndef __01_BASE_STUFF__
#define __01_BASE_STUFF__

#include <iostream>
#include <typeinfo>
#include <string>
#include <fstream>
#include <ostream>


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"


void func_test_something();
void watch_int_from_char();
void left_bit();
void watch_bin_hex();
string convert_10_to_2(string n);

// File
string get_data_from_file();
void write_file();

#endif // !__01_BASE_STUFF__

