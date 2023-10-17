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
	string TestName; // название теста
	int TestId;	 // номер раздела
	int idUser;
	deque<Chapter> chapt;	
	deque<User> user;	
	deque<Result> res;	
	int ColvCorrectAnswer;
	int score;
	double percentage;	

public:
	Test() = default;		
	Test(string name, int id, int idch, int numbQ, string nch, int sc, int idUs);		
	string GetName();		
	void ChoiceChapt();	

	int GetColvCorrectAnswer();
	double Getpercentage();
	int Getscore();
};

	