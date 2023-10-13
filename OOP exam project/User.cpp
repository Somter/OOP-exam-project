#include "User.h"


string User::GetFio()
{
	return FIO;	
}

void User::Print()
{
	cout << FIO << endl;
	cout << address << endl;
	cout << PnoneNumber << endl;
	cout << pasword << endl;
	cout << login << endl;
}
