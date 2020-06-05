#include "03_handle_file.h"

// File
// doc file
vector<string> get_data_from_file(string file_input_name) {
	// func: lấy dữ liệu từ file
	// input: tên file
	// output: mảng dữ liệu đọc được từ file

	fstream fr;
	fr.open(file_input_name, ios::in);

	vector<string> lines;

	if (!fr.is_open()) {
		string error = "Khong mo duoc file!";
		lines.push_back(error);
		return lines;
	}

	string data;
	string line;
	while (!fr.eof())
	{
		getline(fr, line);
		data = line;
		lines.push_back(data);
	}


	fr.close();
	return lines;


}



vector<vector<string>> split_string_data(vector<string> data) {
	// func: tách mảng chuỗi trong file
	// input: mảng chuỗi đã convert từ file
	// output: mảng chuỗi phân biệt đã tách

	vector<vector<string>>rs;
	Utils stuff;
	for (int i = 0; i < data.size(); i++)
	{
		rs.push_back(stuff.tach_chuoi(data[i],' '));
	}
	return rs;
}




vector<string> processing(vector<string> data) {
	// func: xử lý data từ file, trước khi ghi vào file
	// input: mảng chuỗi data lấy từ đọc file,
	// output: mảng chuỗi data sau khi xử lý các chỉ thị


	Utils stuff;

	string p1_base1 = ""; // chỉ thị p1
	string p2_base2 = ""; // chỉ thị p2
	string value_p1 = ""; // giá trị của p1

	vector<vector<string>> data_splited = split_string_data(data);

	vector<string>data_handled;


	// trim(), size # 3,4 file tính sau, chạy được trước đi đã

 	// handler
	for (int i = 0; i < data_splited.size(); i++) {
		// clog << data_splited[i].size() << endl;

		// trường hợp lý tưởng
		// trim(), size chỉ 3 hoặc 4
		// nếu không thì Loi dau vao -> xuất lỗi

		if (data_splited[i].size() == 3) {
			clog << "size = 3" << endl;
			// nếu size = 3 thì 1 là chuyển cơ số, 2 là rol,ror
			string p1_base1 = data_splited[i][0]; // chỉ thị p1
			string p2_base2 = data_splited[i][1]; // chỉ thị p2
			string value_p1 = data_splited[i][2]; // giá trị của p1
			if (p2_base2 == "ror" || p2_base2 == "rol") {
				// nếu rol thì rol
				// Chua lam duoc
				string error = "Chua lam duoc!";
				data_handled.push_back(error);
			}
			else {
				// ngược lại là chuyển base1 sang base2
				int base1 = stuff.convert_string_to_int(p1_base1);
				clog << "Base1: " << base1 << endl;
				if (base1 == 2) {
					// nếu đang là base 2 mà giá trị khác 0,1 thì xuất file lỗi
					if (!stuff.is_base2(value_p1)) {
						// nếu Loi dau vao
						string error = "Loi dau vao!";
						data_handled.push_back(error);
					}
					else {
						// nếu đúng thì chuyển base
						QInt number(value_p1, base1);
						if (p2_base2 == "2") {
							// trường hợp chuyển base 2 sang base 2
							string temp = number.to_string(2);
							data_handled.push_back(temp);
						}
						else if (p2_base2 == "10") {
							// trường hợp chuyển base 2 sang base 10
							string temp = number.to_string(10);
							data_handled.push_back(temp);
						}
						else if (p2_base2 == "16") {
							// trường hợp chuyển base 2 sang base 16
							string temp = number.to_string(16);
							data_handled.push_back(temp);
						}
						else {
							// chuyển base 2 sang base n
							string error = "Chua chuyen base 2 sang base n duoc!";
							data_handled.push_back(error);
						}
				
					}
				}
				
				else if (base1 == 10) {
					// nếu base1 = 10, kiểm tra giá trị khác 0....9 xuất file lỗi
					if (!stuff.is_base10(value_p1)) {
						// nếu Loi dau vao
						string error = "Loi dau vao!";
						data_handled.push_back(error);
					}
					else {
						// nếu đúng thì chuyển base 10 sang base 10,2,16
						QInt number(value_p1, base1);
						if (p2_base2 == "10") {
							// trường hợp chuyển base 10 sang base 10
							string temp = number.to_string(10);
							data_handled.push_back(temp);
						}
						else if (p2_base2=="2") {
							// trường hợp chuyển base 10 sang base 2
							string temp = number.to_string(2);
							data_handled.push_back(temp);
						}
						else if (p2_base2 == "16") {
							// trường hợp chuyển base 10 sang base 16
							string temp = number.to_string(16);
							data_handled.push_back(temp);
						}
						else {
							// chuyển base 10 sang base n
							string error = "Chua chuyen base 10 sang base n duoc!";
							data_handled.push_back(error);
						}

					}
				}
				else if (base1 == 16) {
					// nếu base 16
					QInt number(value_p1, base1);
					if (p2_base2 == "10") {
						// trường hợp chuyển base 16 sang base 10
						string temp = number.to_string(10);
						data_handled.push_back(temp);
					}
					else if (p2_base2 == "2") {
						// trường hợp chuyển base 16 sang base 2
						string temp = number.to_string(2);
						data_handled.push_back(temp);
					}
					else if (p2_base2 == "16") {
						// trường hợp chuyển base 16 sang base 16
						string temp = number.to_string(16);
						data_handled.push_back(temp);
					}
					else {
						// chuyển base 16 sang base n
					
						string error = "Chua chuyen base 16 sang base n duoc!";
						data_handled.push_back(error);
					}
				}
				else {
					// nếu base lớn hơn 16 - Chua lam duoc
					string error = "Chua lam duoc!";
					data_handled.push_back(error);
				}
			
			
				
			

				// number.log(2);

			}
		}
		else if (data_splited[i].size() == 4) {
			// nếu size = 4 thì thực hiện các phép toán, +-*/, dịch bit >>,<<
			// mấy cái này Chua lam duoc
			clog << "size = 4" << endl;
			string error = "Chua lam duoc!";
			data_handled.push_back(error);
		
		}
		else {
		// Nếu size > 4 thì Loi dau vao
			string error = "Loi dau vao!";
			data_handled.push_back(error);
		}
	}
	
	// watch & debug
	/* for (int i = 0; i < data_splited.size(); i++)
	{
		 for (int j = 0; j < 3; j++)
		{	
			 clog << data_splited[i][j] << endl;
		 }
	}*/
	
	//clog << data[0];
	//for (int i = 0; i < data[0].length(); i++) {
	//	clog << i << ":" << data[0][i] << endl;
	//}

	return data_handled;
}




// ghi file
void write_file(string file_input_name, string file_output_name) {
	fstream fw;
	fw.open(file_output_name, ios::out);

	if (!fw.is_open()) {
		clog << "Khong mo duoc file!" << endl;
		return;
	}

	vector<string>data = get_data_from_file(file_input_name);
	vector<string>data_handled = processing(data);

	// xóa dòng thừa cuối cùng trong file ; ))
	int drop_down_the_line_count = 0;

	for (int i = 0; i < data_handled.size(); i++)
	{
		if (drop_down_the_line_count == data_handled.size()-1) {
			//clog << "data handled" << i << ":" << data_handled[i] << endl;
			fw << data_handled[i];
		}
		else {
			//clog << "data handled" << i << ":" << data_handled[i] << endl;
			fw << data_handled[i] + "\n";
		}

		drop_down_the_line_count++;
	}




	clog << "Ghi file thanh cong" << endl;

	fw.close();

}

