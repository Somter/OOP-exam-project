#pragma once
#include <iostream>	
#include<string>
using namespace std;	
class Test
{
private:
	string TestName; // �������� �����
	int TestId;	 // ����� �����
	int quantity;	// ���������� ��������� ���������� �������� 
	int percent; // ������� ���������� �������
	int grade;	// ������

public:
	Test() = default;	
	Test(string name, int id, int q, int p, int g) : TestName(name), TestId(id), quantity(q), percent(p), grade(g) {}
	void PrintTests();

};

