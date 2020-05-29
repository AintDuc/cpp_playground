#include "01_base_stuff.h"

// ham test 1 van de nao do
void func_test_something() {
	clog << "Range: " << sizeof(int) << endl;
}

// xem kieu char khi ep kieu int
void watch_int_from_char() {
	char x = 128;
	clog << (int)x << endl;
}

// xem dich bit 
void left_bit() {
	char x = -24;
	x = x >> 1;
	clog <<x<<">>1 = "<< (int)x << endl;

	unsigned char x2 = -24;
	x2 = x2 >> 1;
	clog << x2 << ">>1 = " << (int)x2 << endl;
}

// xem binary, hexa cua kdl
void watch_bin_hex() {
	__int64 x1 = 0x800000000000;
	clog << x1 << endl;
}


// xem dec -> bin
// hàm test chuyển base 10 qua base 2
string convert_10_to_2(string n) {
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
	clog << n_int+3;
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
			result =  convert_int_to_string_stuff.str()+result;
		}

	}
	clog << "result: " << result << endl;
	return "0";
	// chuỗi nhị phân 16 byte -> 128 bit


}


// File
// doc file
string get_data_from_file() {
	fstream fr;
	fr.open(FILE_INPUT,ios::in);

	if (!fr.is_open()) {

		return "Khong mo duoc file!";
	}

	string data;
	string line;
	while (!fr.eof())
	{
		getline(fr, line);
		data += line + "\n";
	}
	fr.close();
	return data;
}

// ghi file
void write_file() {
	fstream fw;
	fw.open(FILE_OUTPUT, ios::out);

	if (!fw.is_open()) {
		clog << "Khong mo duoc file!" << endl;
		return;
	}
	

	string data = get_data_from_file();
	fw <<data;
	clog << "Ghi file thanh cong!";
	fw.close();
}