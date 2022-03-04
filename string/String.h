#include <ostream>

#ifndef __String__
#define __String__

class String {
public:
    String();
    String(const char*);
    String(const String&);
    String(const String&&);
    ~String();
public:
    String& operator= (const String&);
    String& operator= (const String&&);
    char operator[](int i);
    friend String operator+ (const String& obj1, const String& obj2) {
        String tmp = obj1;
        tmp._size += (obj2._size - 1);
        for(int i = obj1._size, j = 0; i <= tmp._size; ++i, ++j) {
            tmp._str[i] = obj2._str[j];
        }
        return tmp;
    }
    friend std::ostream& operator<< (std::ostream&, String&);
public:
    void insert(int, char*);
    void push_back(char*);
    void pop_back();
    int find(char);
    int at(int);
private:
    unsigned _size;
    char* _str;
};

#endif  //String.cpp
