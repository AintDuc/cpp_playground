#include "02_advance.h"



int main() { 
	Box my_box;
	my_box.length = 10;
	my_box.height = 5;
	my_box.width = 6;
	int volumn = volumn_of_box(my_box);
	clog << "Volumnn of box is: " << volumn << endl;

	int volumn_by_method = my_box.volumn();
	clog << "Volumn by methods: " << volumn_by_method << endl;

	my_box.set_length(500);

	clog << "Length of this box is: " << my_box.get_length() << endl;



	 return 0;
}