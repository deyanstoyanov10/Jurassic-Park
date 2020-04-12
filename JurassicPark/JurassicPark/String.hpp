#pragma once

#include<string.h>
#include<iostream>
#include<fstream>

#define BUFFER 1024

class String
{
public:
	String();
	String(const char* str);
	String(const String& str);
	~String();

	String& operator=(const String& str);
	
	String& operator+= (const char* str);
	String& operator+= (const String& str);

	char operator[](unsigned index) const;
	char& operator[](unsigned index);

	friend String operator+(const String& strLeft, const String& strRight);
	friend String operator+(const String& strLeft, const char* strRight);
	friend String operator+(const char* strLeft, const String& strRight);

	friend bool operator==(const String& strLeft, const String& strRight);
	friend bool operator==(const String& strLeft, const char* strRight);
	friend bool operator==(const char* strLeft, const String& strRight);

	friend bool operator!=(const String& strLeft, const String& strRight);
	friend bool operator!=(const String& strLeft, const char* strRight);
	friend bool operator!=(const char* strLeft, const String& strRight);

	friend std::ostream& operator<< (std::ostream& out, const String& s);
	friend std::istream& operator>> (std::istream& in, String& s);

	void serialize(std::ofstream& ofs);
	void deserialize(std::ifstream& ifs);
public:
	unsigned int size() const { return length; }
private:
	void copy(const String& str);
	void del();
	void setStr(const char* str);
private:
	unsigned int length;
	char* string;
};