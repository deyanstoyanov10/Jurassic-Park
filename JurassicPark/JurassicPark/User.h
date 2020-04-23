#pragma once

#include<string.h>

class User
{
public:
	User(const char* name = "", const char* password = "", bool admin = false);
	User(const User& user);
	User& operator=(const User& user);
	~User();
private:
	void copy(const User& user);
	void clear();
private:
	char* name;
	char* password;
	bool admin;
};