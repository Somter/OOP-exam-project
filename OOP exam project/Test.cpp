#include "Test.h"
#include "Question.h"
#include "Chapter.h"

Test::Test(string name, int id, int idch, int numbQ, string nch, int sc, int idUs)
{
	TestName = name;
	idUser = idUs;	
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
	system("cls");	
	cout << "ÂÛÁÈÐÈÒÅ ÊÎÍÊÐÅÒÍÛÉ ÒÅÑÒ\n";	
	for (int i = 0; i < chapt.size(); i++) {
		cout << i << ". " << chapt[i].GetNameChapt() << endl;	
	}
	cout << "Âàø âûáîð: ";
	cin >> choice;	

	system("cls");
	if (choice >= 0 && choice < chapt.size()) {

		chapt[choice].DefaultQustions();
		chapt[choice].StartTest();

		double percentageCorrect = (static_cast<double>(chapt[choice].GetColvoCorrectAnswer()) / chapt[choice].GetNumberQuestions()) * 100;
		RezultScore = (percentageCorrect / 100) * 12;

		ColvCorrectAnswer = chapt[choice].GetColvoCorrectAnswer();	
		percentage = percentageCorrect;	
		score = RezultScore;
			
	}
	else {
		cout << "Íåäîïóñòèìûé âûáîð òåñòà." << endl;
	}

}

int Test::GetColvCorrectAnswer()
{
	return ColvCorrectAnswer;
}

double Test::Getpercentage()
{
	return percentage;
}

int Test::Getscore()
{
	return score;	
}
