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
	string TestName; // название теста
	int TestId;	 // номер раздела
	//int quantity;	// количество правильно отвеченный вопросов 
	//int percent; // процент правильных ответов
	//int grade;	// оценка
	deque<Chapter> chapt;

public:
	Test() = default;		
	Test(string name, int id, int idch, int numbQ, string nch, int sc);	
	string GetName();		
	void ChoiceChapt();	
};

	