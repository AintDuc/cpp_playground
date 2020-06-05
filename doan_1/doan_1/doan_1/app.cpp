#include "02_QInt.h"
#include "03_handle_file.h"
#include "utils.h"

// main nộp bài

 int main(int argc,char *argv[]) {
	
	// argv[0] - QInt.exe
	// argv[1] - input name
	// argv[2] - output name

	// chuyển sang vector
	 // argv[0] - input name
	// argv[1] - output name


	string current_exec_name = argv[0];
	// clog << current_exec_name;
	vector<string> all_argv;

	if (argc > 1) {
		all_argv.assign(argv + 1, argv + argc);
	}

	write_file(all_argv[0], all_argv[1]);

	return 0;
}



// main debug
//int main() {
//	 char file_in[20] = "input.txt";
//	 char file_out[20] = "output.txt";
//	// process_from_calculator_to_file(file_in, file_out); 
//	//int base = 2;
//	//QInt a("011010101111110111111", base);
//	//a.log(10);
//	 Utils stuff;
//
//	 write_file(file_in, file_out);
//
//
//	// vector<string>data = get_data_from_file(file_in);
//	// vector<string>data_handled = processing(data);
//
//	 // vector<vector<string>>splited = split_string_data(data);
//	
//	/* for (int i = 0; i < splited.size(); i++)
//	 {
//		 for (int j = 0; j < 3; j++)
//		 {
//			 clog << splited[i][j] << endl;
//		 }
//	 }*/
//	 //clog << stuff.is_base2("1001");
//	 //clog << stuff.is_base10("1001294231234567890049");
//	return 0;
//}