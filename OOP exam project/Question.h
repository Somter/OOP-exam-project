#pragma once
#include <iostream>
#include <string>
using namespace std;	

class Question
{
protected:
	string qustion;
	string FirstOption;
	string SecondOption;
	string ThirdOption;	
	int QustionId;	
	int CorrectAnswer;	
public:
	Question() = default;
	Question(string q, string fo, string so, string to, int id, int answ) : qustion(q), FirstOption(fo), SecondOption(so), ThirdOption(to),
		QustionId(id), CorrectAnswer(answ) {}

};

