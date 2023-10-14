#include "User.h"


string User::GetFio()
{
	return FIO;	
}

string User::GetPassword()
{
	return pasword;
}

string User::GetLogin()
{
	return login;	
}

void User::Print()
{
	cout << FIO << endl;
	cout << address << endl;
	cout << PnoneNumber << endl;
	cout << pasword << endl;
	cout << login << endl;
}
