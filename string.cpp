#include <iostream>
#include <cstring>
#include "String.h"

String::String(){
	_size = 0;
	_str = nullptr;
}

String::String(const char* str){
	_size = 1 + strlen(str);
	_str = new char[_size];
	for(int i = 0; i <= _size; i++){
		_str[i] = str[i];
	}
}	

String::String(const String& ns){
	_size = ns._size;
	_str = ns._str;
	for(int i = 0; i < _size; i++){
		_str[i] = ns._str[i];
	}

}

String::String(const String&& ns){
	_size = ns._size;
	_str = ns._str;
	for(int i = 0; i < _size; i++){
		_str[i] = ns._str[i];
	}
}

String::~String()
{
	delete[] _str;
}


String& String::operator= (const String& ns){
	_size = ns._size;
	delete[] _str;
	_str = new char[_size];
	for(int i = 0; i < _size; i++){
		_str[i] = ns._str[i];
	}
	return *this;
}

String& String::operator= (const String&& ns){
	_size = ns._size;
	delete[] _str;
	_str = new char[_size];
	for(int i = 0; i < _size; i++){
		_str[i] = ns._str[i];
	}
	return *this;
}

char String::operator[](int index){
	return _str[index];
}

std::ostream& operator <<(std::ostream& obj, String& ns) {
	for(int i = 0; i < ns._size; ++i) {
		obj << ns._str[i];
	}
	return obj;
}

void String::push_back(char* str){
	int index = _size;
        _size += (strlen(str));
        char* tmp = new char[_size];
        for(int j = 0, i = 0; i < _size; ++j, ++i){
                if(i == index){
                        for(int k = 0; k < strlen(str); ++k, ++i){
                                tmp[i] = str[k];
                        }
                        --i;
                        --j;
                        continue;
                }
                tmp[i] = _str[j];
        }
        delete[] _str;
        _str = tmp;
        tmp = nullptr;

}

void String::insert(int index, char* str){
	_size += (strlen(str));
	char* tmp = new char[_size];
	for(int j = 0, i = 0; i < _size; ++j, ++i){
		if(i == index){
			for(int k = 0; k < strlen(str); ++k, ++i){
				tmp[i] = str[k];
			}
			--i;
			--j;
			continue;
		}
		tmp[i] = _str[j];
	}
	delete[] _str;
	_str = tmp;
	tmp = nullptr;

}


int String::find(char ch){
	for(int i = 0; i < _size; i++){
		if(_str[i] = ch){
			return i;
		}
	}	
	return -1;
}

int String::at(int ind){
	if(ind > _size){
		std::cout << "not valid index" << std::endl;
		return -1;
	}
	return ind;
}

void String::pop_back() {
	_size -= 1;
	_str[_size] = '\0';
	
}





int main(){
	char a[] = {"second"};
	String obj1;
	String obj = "first";
	obj.push_back(a);
	std::cout << obj;
}

