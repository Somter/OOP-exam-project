#pragma once
#include <iostream>
#include <iostream>
#include <string>
using namespace std;	

class Question
{
private:
	string qustion;	
	string FirstOption;
	string SecondOption;
	string ThirdOption;	
	int QustionId;	
	int CorrectAnswer;	
	int ScoreTest;	

public:
	Question() = default;
	Question(string q, string fo, string so, string to, int id, int answ, int st);		
	
	string GetQustion();
	string GetFirstOption();
	string GetSecondOption();
	string GetThirdOption();
	int GetQustionId();
	int GetCorrectAnswer();
	void PrintQustion() {}
	int GetScoreTest();


};

