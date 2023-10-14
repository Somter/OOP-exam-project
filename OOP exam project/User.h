#pragma once
#include <iostream>	
#include<string>
using namespace std;	

class User{
protected:
	string FIO;		
	string address;
	string PnoneNumber;	
	string pasword;
	string login;	
public:	
	User() = default;	
	User(string fio, string addr, string phonumb, string passw, string login): FIO(fio), address(addr), PnoneNumber(phonumb), 
		pasword(passw), login(login){}	
	string GetFio();	
	string GetPassword();
	string GetLogin();
	void Print();				
};	
	
