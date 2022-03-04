#include <iostream>
#include <string>
#include <fstream>


class C_c{
	public:
		C_c(){
		text = "";
		choose = "";
		count_of_shift = 0;
		new_text = "";
		}

	public:
		void code_decode(std::string path){
			std::ifstream fin;
			fin.open(path);
			if(!fin.is_open()){
				std::cout << "file not opened" << std::endl;
				return;
			} else {
				st_w(fin);
				code_or_decode();
				shift_count();
				if("c" == choose){
					code();
				} else {
					decode();
				}
			}

			

		}




	private:
		void st_w(std::ifstream& fin){
			char symbol;
			while(fin.get(symbol)){
				text += symbol;
			}
			std::cout << text << std::endl;
		}

		void code_or_decode(){
			std::cout << "Press >c< if you want to code." << std::endl;
			std::cout << "Press >d< if you want to decode." << std::endl;
			while(true){
				std::cin >> choose;
				if("c" == choose || "d" == choose){ 
					break;
				}
				std::cout << "Press >c< or >d<" << std::endl;
			}
		}

		void shift_count(){
                        std::cout << "insert num of shift please (positiv number for RIGHT shift or negative number for LEFT shift)" << std::endl;
                                std::cin >> count_of_shift;
                }

	

		void code(){
			for(int i = 0; i < text.size(); i++){
				if(static_cast<int>(text[i]) >= 'a' && static_cast<int>(text[i]) <= 'z'){
					new_text += ('a' + ((7 + static_cast<int>(text[i]) + count_of_shift % 26)%26));
					continue;
				}
				if(static_cast<int>(text[i]) >= 'A' && static_cast<int>(text[i]) <= 'Z'){
					new_text += ('A' + ((7 + static_cast<int>(text[i]) + count_of_shift % 26)%26));
					continue;
				}
				new_text += text[i];
			}
			std::ofstream fout;
			fout.open("code.txt");
			if(!fout.is_open()){
				std::cout << "file not opened" << std::endl;
				return;
			} else {
				fout << new_text;
			}
			fout.close();

		}

		void decode(){
			for(int i = 0; i < text.size(); i++){
				if(static_cast<int>(text[i]) >= 'a' && static_cast<int>(text[i]) <= 'z'){
					new_text += ('a' + ((7 + static_cast<int>(text[i]) + count_of_shift % 26)%26));
					continue;
				}
				if(static_cast<int>(text[i]) >= 'A' && static_cast<int>(text[i]) <= 'Z'){
					new_text += ('A' + ((7 + static_cast<int>(text[i]) + count_of_shift % 26)%26));
					continue;
				}
				new_text += text[i];
			}
			std::ofstream fout;
			fout.open("decode.txt");
			if(!fout.is_open()){
				std::cout << "file not opened" << std::endl;
				return;
			} else {
				fout << new_text;
			}
			fout.close();

		}

	private:
		std::string text;
		std::string choose;
		int count_of_shift;
		std::string new_text;
};


int main(){
	C_c obj;
	obj.code_decode("file.txt");
}
