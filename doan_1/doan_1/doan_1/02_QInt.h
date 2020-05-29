#ifndef __QINT__
#define __QINT__
#include "01_base_stuff.h"

// so nguyen lon'
class QInt {
private:
	 int arrays_bits[4];
	 const int total_bits_one_element= 32;
	 const int total_bytes_one_element = 4;
     // 4 byte, 32 bit 1 phần tử
	 // tổng 128 bit big int, 16 byte big int
public:
	QInt();
	QInt(string number,int base=10);
	~QInt();

public:
	string base10_to_base2(string n);

};



// so nguyen 1 byte -128 -> 127
// min 1 000 0000 = -128
// max 0 111 1111 = +127


// so nguyen lon 16 byte 
// min 1 000 0000 = -128
// max 0 111 1111 = +127

#endif // !__QINT__



