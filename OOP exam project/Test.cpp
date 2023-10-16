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
	cout << "\n" << chapt.size() << endl;	
	cout << "�������� ���������� ����\n";	
	for (int i = 0; i < chapt.size(); i++) {
		cout << i << ". " << chapt[i].GetNameChapt() << endl;	
	}
	cout << "��� �����: ";
	cin >> choice;	

	cout << "\n" << choice << endl;	

	

	system("cls");
	if (choice >= 0 && choice < chapt.size()) {

		chapt[choice].DefaultQustions();
		chapt[choice].StartTest();

		double percentageCorrect = (static_cast<double>(chapt[choice].GetColvoCorrectAnswer()) / chapt[choice].GetNumberQuestions()) * 100;
		RezultScore = (percentageCorrect / 100) * 12;

	/*	cout << "���������� ���������� �������: " << chapt[choice].GetColvoCorrectAnswer() << "/" << chapt[choice].GetNumberQuestions() << endl;	
		cout << "������� ���������� �������: " << percentageCorrect << "%" << endl;	
		cout << "������ �� ���������� ����: " << RezultScore << "/" << 12 << endl;	*/

		int testId = choice; // ������������� ���������� �����
		int userId = idUser; // ������������� �������� ������������	

		// �������� ������� Result � ������������
		Result testResult(chapt[choice].GetColvoCorrectAnswer(), RezultScore, percentageCorrect, testId);
	/*	testResult.SetTestId(choice);*/

		// ���������� ����������� � ���������������� ������������
		user[userId].AddCompletedTest(choice);
		user[userId].AddTestResult(testResult);
	}
	else {
		cout << "������������ ����� �����." << endl;
	}

}