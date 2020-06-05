#ifndef __QINT__
#define __QINT__
#include "01_base_stuff.h"
#include "utils.h"

#define __QINT_SIZE__ 16

// so nguyen lớn
class QInt {
private:
	  int arr_bits[4];
	 static const int total_bits_one_element= 32;
	 static const int total_bytes_one_element = 4;

     // 4 byte, 4 phần tử, 32 bit 1 phần tử
	 // tổng 128 bit , 16 byte
public:
	QInt();
	QInt(string number,int base=10);
	~QInt();
public:
	void log(int base);
	string to_string(int base);
	void chua_lam_duoc();
public:
	bool get_arr_bits(int pos);
	void set_arr_bits(int pos, bool value);
public:
	static string dec_to_bin(QInt n);
	static QInt bin_to_dec(string n);
	static string dec_to_hex(QInt n);
	static string bin_to_hex(string n);
public:
	QInt& operator+(const QInt& m);
	QInt& operator-(const QInt& m);
	QInt& operator*(const QInt& m);
	QInt& operator/(const QInt& m);
	QInt& operator=(const QInt& m);
	QInt& operator&(const QInt& m);
	QInt& operator|(const QInt& m);
	QInt& operator^(const QInt& m);
	QInt& operator~();
	QInt& operator>>(const QInt& m);
	QInt& operator<<(const QInt& m);
	bool operator<(const QInt& m);
	bool operator<=(const QInt& m);
	bool operator>(const QInt& m);
	bool operator>=(const QInt& m);
	bool operator==(const QInt& m);
	QInt& operator>>(int);
	QInt& operator<<(int);
	QInt& rol();
	QInt& ror();

};



// so nguyen 1 byte -128 -> 127
// min 1 000 0000 = -128
// max 0 111 1111 = +127


// so nguyen lon 16 byte 
// min 1 000 0000 = -128
// max 0 111 1111 = +127

#endif // !__QINT__



