#pragma once
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

#define CHIEUDAI 5
#define CHIEURONG  10
#define NEWLINE  '\n'
 
// base module  
void type_cpp();
void scope_variable();
int perimeter_of_rectangle(int cd, int cr);
void check_const();
void operator_num();
void relationship_operator();
void logic_operator();
void bit_compare_operator();
void array_type();
void string_type();
void clog_class();


// help func
int decimal_to_binary(int n);


// struct


// struct
struct Books {
	string author;
	string _id;
	string _page;
};


struct Books Book_1;
struct Books Book_2;