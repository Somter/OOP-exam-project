#pragma once
#include <iostream>	
#include<string>
#include <vector>	
#include "Question.h"
#include "Chapter.h"
#include "deque"
#include "Result.h"
#include "User.h"

using namespace std;	
class Test	
{
private:
	string TestName; // �������� �����
	int TestId;	 // ����� �������
	int idUser;
	//int quantity;	// ���������� ��������� ���������� �������� 
	//int percent; // ������� ���������� �������
	//int grade;	// ������
	deque<Chapter> chapt;
	deque<User> user;	

public:
	Test() = default;		
	Test(string name, int id, int idch, int numbQ, string nch, int sc, int idUs);		
	string GetName();		
	void ChoiceChapt();	
};

	