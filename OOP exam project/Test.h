#pragma once
#include <iostream>	
#include<string>
using namespace std;	
class Test
{
private:
	string TestName; // название теста
	int TestId;	 // номер теста
	int quantity;	// количество правильно отвеченный вопросов 
	int percent; // процент правильных ответов
	int grade;	// оценка

public:
	Test() = default;	
	Test(string name, int id, int q, int p, int g) : TestName(name), TestId(id), quantity(q), percent(p), grade(g) {}
	void PrintTests();

};

