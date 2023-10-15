#include "Question.h"
#include <iostream>
#include <string>
#include "deque"    
using namespace std;

Question::Question(string q, string fo, string so, string to, int id, int answ, int st)		
{
	qustion = q;
	FirstOption = fo;	
	SecondOption = so;	
	ThirdOption = to;	
	QustionId = id;	
	CorrectAnswer = answ;
	ScoreTest = st;	
}

string Question::GetQustion()
{
	return qustion;
}	 

string Question::GetFirstOption()
{
	return FirstOption;
}

string Question::GetSecondOption()
{
	return SecondOption;
}

string Question::GetThirdOption()
{
	return ThirdOption;	
}

int Question::GetQustionId()
{
	return QustionId;
}

int Question::GetCorrectAnswer()
{
	return CorrectAnswer;	
}

int Question::GetScoreTest()
{
	return ScoreTest;	
}

