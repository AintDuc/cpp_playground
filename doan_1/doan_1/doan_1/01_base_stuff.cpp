#include "01_base_stuff.h"

// ham test 1 van de nao do
void func_test_something() {
	// test size of kdl
	// clog << "Range: " << sizeof(int) << endl;

	
	// test string.replace
	//string origin = "1001 1001 1100 1011";
	//string base = "this is test string";
	//string str2 = "n example";
	//string str3 = "sample phrase";
	//string str4 = "useful.";


	//clog << base.replace(base.begin()+1, base.end()-3,str3);

	// tìm bit 0 cuối cùng trong chuỗi
	//string n = "1111 1111";
	//size_t last_zero_pos = n.find_last_of('0');

	//if (last_zero_pos != string::npos) {
	//	// nếu tìm thấy, chuyển thành 1, các bit ở sau nó chuyển thành 0
	//	n[last_zero_pos] = '1';
	//	n.replace(n.begin()+last_zero_pos+1, n.end(), n.length()-last_zero_pos-1, '0');
	//}
	//else {
	//	// nếu không tìm thấy, chuyển tất cả các bit thành 0, và chuyển bit đầu thành 1
	//	n.replace(n.begin(), n.end(), n.length(), '0');
	//
	//	n = '1' + n;
	//}

	//clog << n;

	// test substr
	//string temp = "hello world";
	//size_t first_str = temp.find_first_of("w");
	//clog << temp.substr(first_str);



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


// hàm test đưa dãy bit vào QInt
void how_to_bring_arrBits_to_qint() {
	// đưa dãy bit vào QInt như thế nào ?
	// VD: 0000 1010
	// arr_bit[2]
	// arr[0] = 0000, arr[1]=1010


}



void watch_vector() {

	vector<string> test;
	string str1 = "hello world!";
	string str2 = "Nice to meet you!";
	test.push_back(str1);
	test.push_back(str2);
	clog << test.size() << endl;

	for (int i = 0; i < test.size(); i++)
	{

		clog << i << ":" << test[i] << endl;
	}

}


void watch_split_string() {
	//vector<string> data = get_data_from_file(file_in);
	//vector<string> data_handled = processing(data);

	/*vector<string> mangchuoi = stuff.tach_chuoi(data[0], ' ');

	for (int i = 0; i < mangchuoi.size(); i++) {
		clog << mangchuoi[i] << endl;
	}*/
}