#pragma once
#include <iostream>	
#include<string>
#include "Question.h"
#include "Chapter.h"
#include "deque"
using namespace std;	
class Test	
{
private:
	string TestName; // �������� �����
	int TestId;	 // ����� �������
	//int quantity;	// ���������� ��������� ���������� �������� 
	//int percent; // ������� ���������� �������
	//int grade;	// ������
	deque<Chapter> chapt;

public:
	Test() = default;		
	Test(string name, int id, int idch, int numbQ, string nch, int sc);	
	string GetName();		
	void ChoiceChapt();	
};

	