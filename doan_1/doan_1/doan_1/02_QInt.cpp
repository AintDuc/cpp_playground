#include "02_QInt.h"

// constructor
QInt::QInt() {
	for (int i = 0; i < 4; i++)
	{
		this->arr_bits[i] = 0;
	}
}

// destructor
QInt::~QInt() {
	for (int i = 0; i < 4; i++)
	{
		this->arr_bits[i] = 0;
	}
}




QInt::QInt(string n,int base) {
	// method khởi tạo QInt
	// input: số nguyên dạng chuỗi, base cơ số
	// output: khởi tạo QInt base 2,10,16
	
	
	// khởi tạo giá trị 0

	for (int i = 0; i < 4; i++)
	{
		this->arr_bits[i] = 0;
	}



	// nếu base = 2, chuyển về QInt
	if (base == 2) {
		// chuyển về QInt base 10
		QInt temp = bin_to_dec(n);

		for (int i = 0; i < 4; i++) {
			arr_bits[i] = temp.arr_bits[i];
		}

	}

	// nếu base = 10, convert to base 2 -> QInt
	else if (base == 10) {
		// kiểm tra có dấu
		bool is_negative = false;

		if (n[0] == '-') {
			n = n.substr(1);
			// xử lý -0
			if (n != "0") {
				is_negative = true;
			}
		}
		else if (n[0]=='+') {
			n = n.substr(1);
		}

		// chuyển về base 2
		string temp_str;
		while (n != "0") {
			if ((n[n.length() - 1] - '0') % 2 == 0) {
				temp_str = '0' + temp_str;
			}
			else {
				temp_str = '1' + temp_str;
			}
			n = Utils::chia_hai_dang_chuoi(n);
		}
		//Nếu là số âm thì lắp đầy phía trước bằng 1
		
		if (is_negative) {
			if (temp_str.length() >= total_bits_one_element * total_bytes_one_element)
				if (temp_str.length() == total_bits_one_element * total_bytes_one_element && temp_str.find_last_of('1') == 0)
					goto jump;
				else
					throw "Overflow";

			temp_str = Utils::bu_hai(temp_str);
			temp_str.replace(temp_str.begin(), temp_str.begin(), total_bits_one_element * total_bytes_one_element - temp_str.length(), '1');
		}

	jump:
		QInt temp_qint = bin_to_dec(temp_str);
		
		for (int i = 0; i < 4; i++) {
			arr_bits[i] = temp_qint.arr_bits[i];
		}

	}


	// base 16
	else if (base == 16) {
		string temp_str;
		// chuyển dừng ký tự trong chuỗi base 16 sang base 2
		for (int i = n.length(); i >= 0; i--) {
			switch (toupper(n[i]))
			{
			case '0':
				temp_str = "0000" + temp_str;
				break;
			case '1':
				temp_str = "0001" + temp_str;
				break;
			case '2':
				temp_str = "0010" + temp_str;
				break;
			case '3':
				temp_str = "0011" + temp_str;
				break;
			case '4':
				temp_str = "0100" + temp_str;
				break;
			case '5':
				temp_str = "0101" + temp_str;
				break;
			case '6':
				temp_str = "0110" + temp_str;
				break;
			case '7':
				temp_str = "0111" + temp_str;
				break;
			case '8':
				temp_str = "1000" + temp_str;
				break;
			case '9':
				temp_str = "1001" + temp_str;
				break;
			case 'A':
				temp_str = "1010" + temp_str;
				break;
			case 'B':
				temp_str = "1011" + temp_str;
				break;
			case 'C':
				temp_str = "1100" + temp_str;
				break;
			case 'D':
				temp_str = "1101" + temp_str;
				break;
			case 'E':
				temp_str = "1110" + temp_str;
				break;
			case 'F':
				temp_str = "1111" + temp_str;
				break;

			default:
				break;
			}
		}

		
		QInt temp = bin_to_dec(temp_str);

		for (int i = 0; i < 4; i++) {
			arr_bits[i] = temp.arr_bits[i];
		}
	}
	

}




void QInt::log(int base) {
	// method in QInt ra màn hình theo cơ số base
	// input: cơ số
	// output: QInt theo cơ số
	clog<< this->to_string(base);

}

string QInt::to_string(int base) {
	// method chuyển số QInt về dạng chuỗi
	// input: cơ số 
	// output: số QInt cơ số base dạng chuỗi
	if (base == 2) {
		return dec_to_bin(*this);
	}
	else if (base == 10) {
		// chuyển về chuỗi base 2
		string temp_str = dec_to_bin(*this);
		string rs = "0";
		bool is_negative = false;

		//Kiểm tra số cần xuất có phải số âm hay không bằng Bit đầu trong 32 bit.
		if (temp_str[0] == '1' && temp_str.length() == total_bits_one_element * total_bytes_one_element)is_negative = true;

		//Nếu gặp chuỗi biểu diễn số âm thì đưa về dạng bù 2
		if (is_negative)
			temp_str = Utils::bu_hai(temp_str);

		//loại bỏ các bit 0 ở đầu vì không cần thiết
		size_t first1Bit = temp_str.find_first_of('1');
		if (first1Bit != string::npos)
			temp_str = temp_str.substr(first1Bit);
		else
			temp_str = "0";

		//Số Bit còn lại
		int length = temp_str.length();

		//Kiểm tra số Bit có trong chuỗi để tính trước vector 2^i (i từ 0 tới length - 1)
		vector<string> two_pow = Utils::hai_mu_x(length - 1);
		for (int i = 0; i < length; i++) {
			if (temp_str[i] == '1')
				rs = Utils::cong_hai_so(rs, two_pow[length - 1 - i]);
		}

		//Nếu là chuỗi biểu diễn thì âm thì ta thêm dấu - ở phía trước
		if (is_negative)
			rs = '-' + rs;
		return rs;

	}

	else if (base == 16) {
		return dec_to_hex(*this);
	}
	
}

QInt QInt::bin_to_dec(string n) {
	// method: chuyển số nhị phân dạng chuỗi về lưu ở QInt
	// input: chuỗi nhị phân
	// ouput: số QInt biểu diễn nhị phân trên

	QInt result;
	int length = n.length();
	int k = 0;
	//Bắt đầu bật bit từ data[0] --> data[3] (data: [3] [2] [1] [0])
	for (int i = length - 1; i >= 0; i--) {
		//Bật bit nào đó ở data[k]
		if (n[i] == '1')
			result.arr_bits[k] = ((int)1 << ((length - i - 1) % total_bits_one_element)) | result.arr_bits[k];
		//Quăng exception nếu chuỗi nhị phân có ký tự lạ	
		else if (n[i] != '0')
			throw "Sai dinh dang";
	
		//Chuyển sang data[k+1]
		if ((length - i) % total_bits_one_element == 0) k++;
		//Nếu k đã vượt khỏi giới hạn data[3] mà lại phát hiện thêm bit 1 ở phía trước thì quăng exception Overflow
		//Bit 0 không làm ảnh hưởng tới kết quả
		if (i != 0 && k >= total_bytes_one_element && n[i - 1] == '1') throw "Overflow";
	}
	return result;
}

string QInt::dec_to_bin(QInt n) {
	// method chuyển hệ 10 chuỗi sang hệ 2 QInt
	// input: chuỗi số nguyên n
	// output: QInt hệ 2

	// vd: 10 dec -> x bin
	// 10:2 = 5 - 0
	// 5:2 = 2 - 1
	// 2:2 = 1 - 0
	// 1:2 = 0 - 1
	// 10 dec =  1010 bin

	string rs;
	for (int i = 0; i < QInt::total_bytes_one_element; i++) {
		for (int j = 0; j < QInt::total_bits_one_element; j++)
			rs = (char)(((n.arr_bits[i] >> j) & 1) + '0') + rs;
	}

	//loại bỏ các bit 0 ở đầu vì không cần thiết phải xuất cho người dùng xem
	size_t first1Bit = rs.find_first_of('1');
	if (first1Bit != string::npos)
		rs = rs.substr(first1Bit);
	else
		rs = "0";	
	return rs;
}


bool QInt::get_arr_bits(int pos) {
	int byte_pos = __QINT_SIZE__ - 1 - pos / 8;
	int bit_pos = pos % 8;
	return ((this->arr_bits[byte_pos] >> bit_pos) & 1);
}


void QInt::set_arr_bits(int pos, bool value) {

}


string QInt::dec_to_hex(QInt n) {
	// method: chuyển số base 10 QInt về chuỗi base 16
	// input: số QInt n
	// output: chuỗi QInt base 16

	// chuyển về chuỗi base 2
	string n_bin = dec_to_bin(n);
	// chuyển base 2 sang base 16
	return bin_to_hex(n_bin);
}

string QInt::bin_to_hex(string n) {
	// method:   chuyển từ số nhị phân ở dạng string và trả về dạng string biểu diễn dạng thâp lục phân của nó
	// Input: Số nhị phân cần chuyển đổi (string).
	// Output: Số thập nhị phân là kết quả chuyển đổi (string).
	
	const int VALUE_TO_SPLIT_BIT = 4;
	string rs;
	int start_pos, end_pos;
	start_pos = end_pos = n.length();

	do {
		// chọn vị trí bắt đầu cắt chuỗi 4 bit
		if (start_pos >= VALUE_TO_SPLIT_BIT) {
			start_pos -= VALUE_TO_SPLIT_BIT;
		}
		else {
			start_pos = 0;
		}
		// thêm 0 ở đầu
		string temp = "0"+ n.substr(start_pos, end_pos - start_pos);
		//Chuyển về số nguyên và xét từng chuỗi 4 bit để đưa vào chuỗi kết quả
		switch (stoi(temp)) {
		case 0:
			rs = "0" + rs;
			break;
		case 1:
			rs = "1" + rs;
			break;
		case 10:
			rs = "2" + rs;
			break;
		case 11:
			rs = "3" + rs;
			break;
		case 100:
			rs = "4" + rs;
			break;
		case 101:
			rs = "5" + rs;
			break;
		case 110:
			rs = "6" + rs;
			break;
		case 111:
			rs = "7" + rs;
			break;
		case 1000:
			rs = "8" + rs;
			break;
		case 1001:
			rs = "9" + rs;
			break;
		case 1010:
			rs = "A" + rs;
			break;
		case 1011:
			rs = "B" + rs;
			break;
		case 1100:
			rs = "C" + rs;
			break;
		case 1101:
			rs = "D" + rs;
			break;
		case 1110:
			rs = "E" + rs;
			break;
		case 1111:
			rs = "F" + rs;
			break;
		default:
			break;
		}
		end_pos = start_pos;
		if (start_pos == 0) {
			break;
		}
	} while (1);

	return rs;
}




QInt& QInt::operator&(const QInt& m)
{
	return *this;
}
QInt& QInt::operator+(const QInt& m)
{
	return *this;
}
QInt& QInt::operator-(const QInt& m)
{
	return *this;
}
QInt& QInt::operator*(const QInt& m)
{
	return *this;
}
QInt& QInt::operator/(const QInt& m)
{
	return *this;
}
QInt& QInt::operator|(const QInt& m)
{
	return *this;
}
QInt& QInt::operator^(const QInt& m)
{
	return *this;
}
QInt& QInt::operator=(const QInt& m)
{
	return *this;
}
QInt& QInt::operator~()
{
	return *this;
}
QInt& QInt::operator>>(const QInt& m)
{
	return *this;
}
QInt& QInt::operator<<(const QInt& m)
{
	return *this;
}
QInt& QInt::operator<<(int move)
{
	return *this;
}
QInt& QInt::operator>>(int move)
{
	return *this;
}

bool QInt::operator<=(const QInt& m)
{
	return true;
}
bool QInt::operator<(const QInt& m)
{
	return true;
}
bool QInt::operator>(const QInt& m)
{
	return true;
}
bool QInt::operator>=(const QInt& m)
{
	return true;
}
bool QInt::operator==(const QInt& m)
{
	return true;
}
QInt& QInt::rol()
{
	return *this;
}
QInt& QInt::ror()
{
	return *this;
}


void QInt::chua_lam_duoc() {
	clog << "Chua lam duoc!" << endl;
}