#include "Test.h"
#include "Question.h"
#include "Chapter.h"
Test::Test(string name, int id, int idch, int numbQ, string nch, int sc)	
{
	TestName = name;
	TestId = id;	
	chapt.push_back(Chapter(idch, numbQ, nch, sc));		
}

string Test::GetName()
{
	return TestName;
}

void Test::ChoiceChapt()
{
	int choice;	
	int RezultScore;	
	cout << "ВЫБИРИТЕ КОНКРЕТНЫЙ ТЕСТ\n";	
	for (int i = 0; i < chapt.size(); i++) {
		cout << i << ". " << chapt[i].GetNameChapt() << endl;	
	}
	cout << "Ваш выбор: ";
	cin >> choice;	
	
	chapt[choice].DefaultQustions();	
	chapt[choice].StartTest();	

	double percentageCorrect = (static_cast<double>(chapt[choice].GetColvoCorrectAnswer()) / chapt[choice].GetNumberQuestions()) * 100;
	RezultScore = (percentageCorrect / 100) * 12;

	system("cls");
	cout << "Количество правильных ответов: " << chapt[choice].GetColvoCorrectAnswer() << "/" <<  chapt[choice].GetNumberQuestions() << endl;	
	cout << "Процент правильных ответов: " << percentageCorrect << "%" << endl;	
	cout << "Оценка за пройденный тест: " << RezultScore  << "/" << 12 << endl;	
}