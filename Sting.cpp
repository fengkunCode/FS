//模拟实现string
#pragma once
#include<iostream>
using namespace std;
#include<assert.h>


namespace STR{
	class string{
	public:
		typedef char* iterator;
		iterator begin(){
			return _str;
		}
		iterator end(){
			return _str + _size;
		}
		iterator rbegin(){
			return _str+_size;
		}
		iterator rend(){
			return _str;
		}
		string(char * str=""){
			if (nullptr == str)
			{
				str = "";
			}
			_size = strlen(str);
			_str = new char[_size + 1];
			strcpy(_str, str);
			_capacity = _size;
		}

		string(size_t n, char ch)
			:_str(new char[n+1])
			, _size(n)
			, _capacity(n)
		{
			memset(_str, ch, _size);
			_str[_size] = '\0';
		}

		string(const string& s)
			:_size(s._size)
			, _capacity(s._capacity)
		{
			_str = new char(_size + 1);
			strcpy(_str, s._str);
		}

		~string(){
			if (_str){
				delete[] _str;
				_str = nullptr;
			}
		}

		string& operator=(const string& s){
			if (this != &s)
{
				char* str = new char[s._size + 1];
				strcpy(str, s._str);
				delete[] _str;
				_str = str;
				_size = s._size;
				_capacity = s._capacity;
			}
		}

		char& operator[](size_t index){
			assert(index < _size);
			return _str[index];
		}
		const char& operator[](size_t index)const{
			assert(index < _size);
			return _str[index];
		}

		size_t size()const{
			return _size;
		}

		size_t capacity()const{
			return _capacity;
		}
		void resize(size_t newSize,char ch=char()){
			size_t oldSize = _size;
			if (newSize > oldSize)
			{
				if (newSize > _capacity)
				{
					reserve(_capacity);
				}
				memset(_str + _size, ch, newSize - oldSize);
			}
			_size = newSize;
			_str[_size] = '\0';
		}

		void reserve(size_t newCapacity){
			if (newCapacity>_capacity)
			{
				char *str = new char[newCapacity + 1];
				strcpy(str, _str);
				delete[] _str;
				_str = str;
				_capacity = newCapacity;
			}
		}

		string& operator+=(char ch){
			if (_size == _capacity)
				reserve(2 * _capacity);
			_str[_size++] = ch;
			_str[_size] = '\0';
			return *this;
		}
		string& operator+=(char* str){
			size_t len = strlen(str);
			size_t newSize = size() + len;
			if (capacity() <newSize)
			{
				reserve(newSize);
			}
			strcat(_str, str);
			_size = newSize;
		}

		string& operator+=(const string& s){
			*this += s._str;
			return *this;
		}
		
		//string& append();
		//insert()
		//replace()
		/*
		void swap(string& s){
			swap(_str, s._str);
			swap(_size, s._size);
			swap(_capacity, s._capacity);
		}
		*/
		//获取c类型的字符串
		const char* c_str()const{
			return _str;
		}

		size_t find(char ch){
			for (size_t i = 0; i < _size; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}
		size_t rfind(char ch){
			for (size_t i = _size; i >=0; i++)
			{
				if (_str[i] == ch)
					return i;
			}
			return npos;
		}

		string substr(size_t pos = 0, size_t n = npos){
			if (n == npos)
				n = size() - pos;

			string strRet;
			strRet.reserve(n);
			strcpy(strRet._str, _str + pos);
			strRet._size = n;
			strRet._str[n] = '\0';
			return strRet;
		}

		friend ostream& operator<<(ostream& _cout, const string& s){
			_cout << s.c_str();
			return _cout;
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
		static size_t npos;
	};
	size_t string::npos = 0;

}




#if 0
class String{
public:
	String(const char* str="")
	{
		if (nullptr == str)
		{
			_str = new char[1];
			*_str = '\0';
		}
		
		else
		{
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}

	}

	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}


private:
	char *_str;
};



int main()
{
	String s1;
	String s2("hello");
	String s3(nullptr);
	return 0;
}

#endif





