
#include "utils.h"



// constructor
Utils::Utils() {}
// destructor
Utils::~Utils(){}

string Utils:: cong_mot(string n) {
	// method cộng 1 phục vụ việc chuyển bù 2
	// input: chuỗi bit 
	// output: chuỗi bit sau khi cộng thêm 1

	// vd:  0000 1010
	//     +		1
	//		0000 1011

	// vd  0000 1011
	//    +		   1
	//     0000 1100

	// tìm bit 0 cuối cùng của chuỗi 
	string result = n;

	size_t last_zero_pos = result.find_last_of('0');

	if (last_zero_pos != string::npos) {
		// nếu tìm thấy, chuyển thành 1, các bit sau nó chuyển thành 0
		result[last_zero_pos] = '1';
		result.replace(result.begin()+last_zero_pos+1, result.end() , result.length()-last_zero_pos-1, '0');
	}
	else {
		// ngược lại, chuyển tất cả các bit thành 0, bit đầu thành 1
		result.replace(result.begin(), result.end(), result.length(), '0');
		result = '1' + result;

	}

	return result;

}

string Utils::bu_hai(string n) {
	// method chuyển chuỗi bit n thành bù 2
	// input: chuỗi bit n
	// output: chuỗi bù 2 của dãy bit n

	// vd: 1001 1010
	//     0110 0101
	//    +		   1
	// ->  0110 0110

	// đảo bit
	string result = n;
	int len = result.length();
	for (int i = 0; i < len; i++) {
		if (result[i] == '0') {
			result[i] = '1';
		}
		else {
			result[i] = '0';
		}
	}

	result = cong_mot(result);
	return result;

}


int Utils::convert_string_to_int(string str) {
	// method chuyển chuỗi sang số nguyên 
	// input: chuỗi str base 10
	// ouput: số nguyên của chuỗi str
	int rs;
	istringstream convert(str);
	if (!(convert >> rs)) {
		rs = 0;
	}
	return rs;
}

string Utils::convert_int_to_string(int n) {
	// method: chuyển số sang chuỗi
	// intput: số n base 10
	// output: chuỗi thể hiện số n
	string rs;
	ostringstream convert;
	convert << n;
	rs = convert.str();
	return rs;
}



// convert base 10 to base 2

// if n > 0
// n / 2 = k, chia lay du, roi lay kech qua chia 2 tiep denh khi bang 0
// tu trenh xuong duoi la ghi tu phai sang trai

// if n = 0 - 0

// if n < 0
// lam theo n > 0, dao bit , sau do cong 1 vao kech qua

// vd: n = 118
// 118 : 2 = 59 - 0
// 59 : 2 = 29 - 1
// 29 : 2 = 14 - 1
// 14 : 2 = 7 - 0
// 7 : 2 = 3 - 1
// 3 : 2 = 1 - 1
// 1 : 2 = 0 - 1
// ->>	00 0111 0110

// vd: n = -118
// n1 = 118 - 00 0111 0110
// 11 1000 1001
// 11 1000 1010
// ->> -118 = 11 1000 1010 (2)


int convert_base_10_to_base_2(int n) {
	return 0;
}


// convert base 2 to base 10
// + B1: kiem tra bit dau cua nhi phan, neu 1 la so am, 0 la duong

//  if bit dau = 0 - so duong
// + B2: Chuyen sang thap phan - ketqua = tong cac tich cua cac ki tu nhi phan nhan 2 mu~ vi tri

//  if bit dau = 1 - so am
// + B3: Tru di 1 cua cac bit
// + B4: Dao bit o buoc 3 sau do lam nhu B2, sau do them dau - vao kq

// VD: convert n =  00 0100 0111 from base 2 to base 10
// 0 -> so duong
// kq = 0x2^9+0x2^8+0x2^7+1x2^6+0x2^5+0x2^4+0x2^3+1x2^2+1x2^1+1x2^0 = 71
// -> 00 0100 0111(2) = 71 (10)

// VD: convert n =  11 1011 1001 from base 2 to base 10
// 1 -> so am
//  11 1011 1001
//-			   1
// -------------
//  11 1011 1000 
// dao bit: 00 0100 0111
// kq = 0x2^9 + 0x2^8 + 0x2^7 + 1x2^6 + 0x2^5 + 0x2^4 + 0x2^3 + 1x2^2 + 1x2^1 + 1x2^0 = 71
// ->>> 11 1011 1001 base 2 = -71 base 10


// Tìm dãy bit nhị phân của số nguyên 16 byte có dấu


bool Utils::get_bit(int x, int i) {
	// method: lấy 1 bit của x tại vị trí i từ phải sang
	// input: số x, vị trí i
	// output: bit tại vị trí i
	return (x >> i) & 1;
}
bool* Utils::find_arr_bits(int x) {
	// method: tìm dãy bit của số x
	// input: số x
	// output: dãy bit của x
	bool* rs = new bool[128];
	int k = 0;
	for (int i = 127; i >= 0; i--) {
		bool bit = get_bit(x, i);
		rs[k++] = bit;
	}
	return rs;
}

void Utils::log_arr_bits(bool* arr_bits) {
	// method: xuất dãy bit 
	// input: mảng bit
	// output: mảng bit

	for (int i = 0; i < 128; i++)
	{
		clog << arr_bits[i];
	}
}


string Utils::chia_hai_dang_chuoi(string number) {
	// method: chia số dạng chuỗi cho 2
	// input: số dạng chuỗi
	// output: kết quả phần nguyên dạng chuỗi
	const int DIVISOR = 2;
	string rs;
	int curID = 0;

	//Chuyển về số nguyên để lấy số bị chia đầu tiên
	int temp = number[0] - '0';
	//Tiếp tục tìm cho đến khi tìm được số bị chia thích hợp > DIVISOR = 2.
	while (temp < DIVISOR && curID < number.length() - 1)
		temp = temp * 10 + (number[++curID] - '0');

	//Nếu sau khi tìm vẫn chưa tìm được thì chứng tỏ số bị chia ban đầu đã nhỏ hơn 2, trả về 0.
	if (temp < DIVISOR) return "0";

	//Lặp cho đến hết chuỗi
	while (number.length() > curID) {
		rs = rs + (char)(temp / DIVISOR + '0');
		temp = (temp % DIVISOR) * 10 + (number[++curID] - '0');
	}
	return rs;

}

vector<string> Utils::hai_mu_x(int x)
{

	/* method: tính ra một mảng số từ 2^0 --> 2^x, mỗi số được lưu ở dạng chuỗi, phục vụ cho việc chuyển nhị phân sang thập phân
	* Input: Số nguyên x dương
	* Output: mảng kết quả lưu ở dạng vector, mỗi phần tử là 1 string
	* Lưu ý: Do việc tính từ số nhị phân sang số thập phân phải tính đến 2^x rất nhiều lần, do đó ở đây ta có thể
	* đưa vào một số x = độ dài chuỗi bit - 1 để việc tính toán các lần sau không gây mất thời gian.
	*/
	vector<string> result;
	//tạo phần tử 2^0
	result.push_back("1");
	//phần tử sau bằng phần tử trước *2, tức là tổng 2 số trước
	for (int i = 1; i <= x; i++) {
		result.push_back(cong_hai_so(result[i - 1], result[i - 1]));
	}
	return result;
}

 string Utils::cong_hai_so(string number1, string number2) {
	 /* method: cộng 1 số lớn với một số khác, cả 2 ở dạng string 
	* Input: 2 số dương ở dạng string
	* Output: Chuỗi kết quả ở dạng string sau khi cộng 2 số
	* Lưu ý: Chỉ thực hiện được với 2 số dương
	*/
	 int n1, n2, n;
	 string result;
	 n1 = number1.length();
	 n2 = number2.length();
	 n = n1 > n2 ? n1 : n2;
	 if (n2 > n1) number1.swap(number2);
	 //Mặc định cho number1 là số lớn hơn

	 //fill đầy chuỗi number 2 bằng số 0 ở đầu sao cho chiều dài đúng bằng chuỗi number1
	 string temp;
	 temp.resize(n - number2.length(), '0');
	 number2 = temp + number2;
	 //Số cần nhớ
	 int carry = 0;
	 for (int i = n - 1; i >= 0; i--) {
		 int temp = (number1[i] - '0') + (number2[i] - '0') + carry;
		 result = (char)(temp % 10 + '0') + result;
		 carry = temp / 10;
	 }
	 //nếu tính hết rồi mà còn dư số nhớ thì đưa nó về đầu chuỗi kết quả
	 if (carry != 0)
		 result = (char)(carry + '0') + result;
	 return result;
}




 vector<string> Utils::tach_chuoi(string& s,char delimeter) {
	 // method: tách chuỗi (split)
	 // input: chuỗi s cần tách - tham chiếu để thay đổi giá trị, delimeter dấu phân cách "  " hay bất kì ký tự lạ
	 // output: mảng chuỗi sau khi phân tách

	 vector<string> tokens;
	 string token;
	 istringstream token_stream(s);
	 while (getline(token_stream,token,delimeter)) {
		 tokens.push_back(token);
	 }
	 return tokens;
 }


 bool Utils::is_base2(string value) {
	// method: kiểm tra có đúng dạng base 2 không
	// input: chuỗi số 
	// output: đúng nếu có dạng (0,1), sai nếu ngược lại

	 // 1001
	 for (int i = 0; i < value.length(); i++)
	 {
		 if (value[i] != '1'&&value[i]!='0') {
			 return false;
		 }
	 }
	 return true;
 }

 bool Utils::is_base10(string value) {
	// method: kiểm tra có đúng dạng base 10 không
	// input: chuỗi số 
	// output: đúng nếu có dạng (0,1,...,9), sai nếu ngược lại
	 for (int i = 0; i < value.length(); i++)
	 {
		 if (value[i] != '1' && value[i] != '0' && value[i] != '2' && value[i] != '3' && value[i] != '4'
			 && value[i] != '5' && value[i] != '6' && value[i] != '7' && value[i] != '8' && value[i] != '9') {
			 return false;
		 }
	 }
	 return true;

 }