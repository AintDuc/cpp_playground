#include "01_base_library.h"



// check type
void type_cpp() {
	cout << "Hello type cpp!" << endl;
	bool b = true;
	cout << "Bool: " << b << endl;
	char x = 'c';
	cout << "Char: " << x << endl;
	int i = 500;
	cout << "Int: " << i << endl;
	float f = 500.500;
	cout << "Float: " << f << endl;
	double db = 500.500;
	cout << "Double: " << db << endl;
	wchar_t wct = 123;
	cout << "wchar_t: " << wct << endl;
}


// check scope variable
int global_var = 0;
void scope_variable() {
	int a=2, b = 1;
	int c = a + b;
	cout << c<<endl;

	a = b = 5;
	c = 10;
	cout << a << b << c<<endl;
	global_var = c + a + b;
	cout << global_var;
}

// check #define variable
int perimeter_of_rectangle(int cd,int cr) {
	return (cd + cr) * 2;
}


// const
void check_const() {
	const int a = 5;
	cout << a;
}

// operator	numerals
void operator_num() {
	int a =5, b = 2, c = a + b;
	cout << a<< " + "<<b <<" = " << a+b << endl;
	cout << a << " - " << b << " = " <<a-b << endl;
	cout << a << " x " << b << " = " << a*b << endl;
	cout << a << " / " << b << " = " << a/b << endl;
	cout << a << " % " << b << " = " << a%b<< endl;
	cout <<a++<< "++"  << " = " << a<< endl;
}

// relationship operator
void relationship_operator() {
	bool a = true;
	bool b = false;

	cout << a << " <= " << b << " ? "<<(a <= b) << endl;
	cout << a << " >=  " << b << " ? " << (a >= b) << endl;
	cout << a << " ==  " << b << " ? " << (a == b) << endl;
	cout << a << " != " <<b<< " ? " << (a != b) << endl;
}

// logic operator
void logic_operator() {
	bool a = true, b = false;
	cout << a << "&&" << b << " = " << (a && b) << endl;
	cout << a << "||" << b << " = " << (a || b) << endl;
}

// bit compare operator 
void bit_compare_operator() {
	int a = 60;
	int b = 13;
}

// decimal to binary
int decimal_to_binary(int n) {
	int binaryNum[32];

	int i = 0;
	while (n > 0) {
		binaryNum[i] = n % 2;
		n = n / 2;
		i++;
	}

	for (int j = i - 1; j >= 0; j--) {
		cout << binaryNum[j];
	}
	cout << endl;
	cout <<"Type: " <<typeid(binaryNum).name();
	return binaryNum[32];
}


// array
void array_type() {
	const int length = 50;
	int arr[length];
	for (int i = 0; i < length; i++) {
		arr[i] = i;
	}
	for (int i = 0; i < length; i++) {
		// cout << arr[i];	
	}

	char c[length];
	for (int i = 0; i < length; i++) {
		c[i] = char(i);
	}

}

// string
void string_type() {
	string str = "hellllooooo";
	cout << str;
	cout << "Type: " << typeid(str).name() << endl;
	clog << str;
}


// clog class
void clog_class() {
	clog << "Hello";
	int a = 1, b = 2;
	clog << a << b << a + b;
}


