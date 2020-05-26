#pragma once

#include <iostream>
#include <typeinfo>
#include <string>

#include <fstream>
#include <ostream>
using namespace std;

#define FILE_INPUT "input.txt"
#define FILE_OUTPUT "output.txt"


// OOP
// class
class Box {
	public:
		int length;
		int width;
		int height;

		// constructor - destructor
		Box(void);
		~Box(void);
		int get_length();
		void set_length(int length);


		int volumn();
};


void read_file();
void write_file();
int volumn_of_box(Box b);





