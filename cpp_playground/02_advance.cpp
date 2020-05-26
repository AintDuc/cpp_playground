#include "02_advance.h"


// File

// read file
void read_file() {
	fstream fr;

	fr.open(FILE_INPUT,ios::in);
	string data_from_file;
	
	string line;
	while (!fr.eof())
	{
		getline(fr, line);
		data_from_file = data_from_file + line + "\n";
	}

	fr.close();
	cout << data_from_file;
}



// write file
void write_file() {
	fstream fw;
	fw.open(FILE_OUTPUT, ios::out);

	string data_write = "Xin chao\nGhi Dong nay vao\n";
	fw << data_write;

	clog << "Ghi file thanh cong!";
	fw.close();
}


// the tich hop
int volumn_of_box(Box b) {
	return b.length * b.width * b.height;
}


// methods of class
int Box:: volumn() {
	return this->length * this->height * this->width;
}

int Box::get_length() {
	return this->length;
}


void Box::set_length(int length) {
	this->length = length;
}

// constructor - default method of any class
Box::Box(void) {
	clog << "Box is created!" << endl;
}

Box::~Box(void) {
	clog << "Box is deleted!" << endl;
}