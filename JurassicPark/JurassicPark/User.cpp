#pragma warning(disable: 4996)
#include "User.h"

User::User(const char* name, const char* password, bool admin)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);

	this->admin = admin;
}

User::User(const User& user) : User()
{
	if (this != &user)
	{
		copy(user);
	}
}

User& User::operator=(const User& user)
{
	if (this != &user)
	{
		clear();
		copy(user);
	}

	return *this;
}

User::~User()
{
	clear();
}

void User::copy(const User& user)
{
	this->name = new char[strlen(user.name) + 1];
	strcpy(this->name, user.name);

	this->password = new char[strlen(user.password) + 1];
	strcpy(this->password, user.password);

	this->admin = user.admin;
}

void User::clear()
{
	delete[] name;
	delete[] password;
}
