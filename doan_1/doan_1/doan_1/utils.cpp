
#include "utils.h"

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