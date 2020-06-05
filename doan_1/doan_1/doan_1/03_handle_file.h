#ifndef __HANDLE__FILE__
#define __HANDLE__FILE__

#include "01_base_stuff.h"
#include "02_QInt.h"



// File handle
vector<string> get_data_from_file(string file_input_name);
vector<string> processing(vector<string> data);
vector<vector<string>> split_string_data(vector<string> data);
void write_file(string file_input_name, string file_output_name);
#endif
