#ifndef __UTILS__
#define __UTILS__


#include "01_base_stuff.h"

class Utils {
public:
	Utils();
	~Utils();
	static string cong_mot(string n);
	static string bu_hai(string n);
	static string chia_hai_dang_chuoi(string number);
	static vector<string> hai_mu_x(int x);
	static string cong_hai_so(string number1, string number2);
	static vector<string> tach_chuoi(string& s, char delimeter);
public:
	int convert_string_to_int(string str);
	string convert_int_to_string(int n);
public:
	bool get_bit(int x, int i);
	bool* find_arr_bits(int x);
	void log_arr_bits(bool* arr_bits);
public:
	bool is_base2(string value);
	bool is_base10(string value);

};


#endif __UTILS__