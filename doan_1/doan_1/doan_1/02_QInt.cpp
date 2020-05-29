#include "02_QInt.h"

// constructor
QInt::QInt() {}

// destructor
QInt::~QInt() {}




QInt::QInt(string number,int base) {
	// method khởi tạo QInt
	// input: số nguyên dạng chuỗi, base, mặc định là base 10
	// output: khởi tạo QInt base 2

	// clog << number << endl;



	// nếu base = 10 - chuyển sang base 2
	if (base == 10) {
		for (int i = 0; i < 4; i++) {
			this->arrays_bits[i] = 10;
		}

		string base2_after_convert = base10_to_base2(number);
		clog << base2_after_convert << endl;
	}

	for (int i = 0; i < 4; i++) {
		clog << this->arrays_bits[i];
	}

}


string QInt::base10_to_base2(string n) {
	// vd: n = 10
	// 10:2=5 0
	// 5:2=2 1
	// 2:2=1 0
	// 1:2=0 1
	// -> 10 dec = 0000 0101 bin
	istringstream convert_string_to_number_stuff(n);
	int n_int = 0;
	int r = 0;
	if (!(convert_string_to_number_stuff >> n_int)) {
		n_int = 0;
	}
	clog << n_int + 3;
	string result = "";
	if (n_int == 0) {
		return "0";
	}
	else if (n_int < 0) {

	}
	else {
		while (n_int != 0) {
			n_int = n_int / 2;
			r = n_int % 2;

			ostringstream convert_int_to_string_stuff;
			convert_int_to_string_stuff << r;
			result = convert_int_to_string_stuff.str() + result;
		}

	}
	clog << "result: " << result << endl;
	return "0";
	// chuỗi nhị phân 16 byte -> 128 bit

}
