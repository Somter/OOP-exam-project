// OOP exam project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <deque>
#include <vector> 
#include <windows.h>
#include "User.h"
#include "Test.h"
#include "Question.h"
#include "Chapter.h"
#include "Result.h" 
#include <algorithm>
#include<map>				
using namespace std;
	
int main() {
	setlocale(LC_ALL, "");	
	deque <User> users;		
	deque<Test> tests;
	vector<Result> result;	

	string userFirstname;
	string userLastname;
	string userSurname;		
	string userAddress;		
	string userPhoneNumber;			
	string userPasword; 
	string userLogin;	

	int choice;
	static int count = 0;
	int choiceAccaunt;	 
	int choiceTest;	
	string checkPasword;
	string checkLogin;

	int ColvCorrectAnswer;
	int score;
	double percentage;		

	while (true) {
		tests.push_back(Test("����������", 1, 1, 6, "������������ ����������", 2 ,count));	

		cout << "�������� �����: \n";
		cout << "1 - �����������\n";
		cout << "2 - �������������\n";
		cout << "��� �����: ";
		cin >> choice; // ����� ������
		system("cls");
		switch (choice) {
		case 1:	// �����������	
		
			// 1. �����������  	
			if (count == 0) {
				cout << "�����������\n";

				cout << "������� �������: ";
				cin.ignore();	
				getline(cin, userFirstname);


				cout << "������� ���: ";
				cin.ignore();
				getline(cin, userLastname);

				cout << "������� ��������: ";
				cin.ignore();
				getline(cin, userSurname);

				cout << "������� ��� �����: ";
				getline(cin, userAddress);
				 
				cout << "������� ��� ����� �������� (10 ����): ";
				while (true) {
					getline(cin, userPhoneNumber);

					if (userPhoneNumber.size() == 10 && all_of(userPhoneNumber.begin(), userPhoneNumber.end(), isdigit)) {
						break;
					}

					cout << "������������ ����� ��������. ����������, ������� 10 ����: ";
				}

				cout << "������� ��� ������: ";
				cin >> userPasword;

				cout << "������� ��� �����: ";
				cin >> userLogin;

				system("cls");
				cout << "����������� ������� ���������\n";
				Sleep(2000);
				system("cls");
				users.push_back(User(userFirstname, userLastname, userSurname, userAddress, userPhoneNumber, userPasword, userLogin));
	
				system("cls");
				int ChoiceTest;
				cout << "�������� ������ ��� ����������� �����\n";

				for (int i = 0; i < tests.size(); i++) {
					cout << i << ". " << tests[i].GetName() << endl;
				}

				cout << "��� �����: ";
				cin >> ChoiceTest;
				tests[ChoiceTest].ChoiceChapt();

				ColvCorrectAnswer = tests[ChoiceTest].GetColvCorrectAnswer();	
				score = tests[ChoiceTest].Getscore();
				percentage = tests[ChoiceTest].Getpercentage();

				result.push_back(Result(ColvCorrectAnswer, score, percentage, count));	
				result[count].PrintRezult();	

			}
			else { // count > 0
				cout << "�������� �ר���� ������\n";
				for (int i = 0; i < users.size(); i++) {
					cout << i << ". " << users[i].GetFirstname() << endl;
				}
				int ChoiceAccaunt;
				cout << "��� �����: ";

				try {
					cin >> ChoiceAccaunt;
					if (ChoiceAccaunt >= users.size() || ChoiceAccaunt < 0) {
						throw 1;
					}

					bool loggedIn = false;
					int attempts = 3;

					while (attempts > 0) {

						cout << "������: ";
						string CheckPassword;
						cin >> CheckPassword;
						cout << "�����: ";
						string CheckLogin;
						cin >> CheckLogin;

						if (CheckPassword == users[ChoiceAccaunt].GetPassword() && CheckLogin == users[ChoiceAccaunt].GetLogin()) {

							loggedIn = true;	
							system("cls");	
							int ChoiceTest;
							cout << "�������� ������ ��� ����������� �����\n";
							for (int i = 0; i < tests.size(); i++) {
								cout << i << ". " << tests[i].GetName() << endl;
							}
							cout << "��� �����: ";
							cin >> ChoiceTest;
							system("cls");
							tests[ChoiceTest].ChoiceChapt();

							ColvCorrectAnswer = tests[ChoiceTest].GetColvCorrectAnswer();	
							score = tests[ChoiceTest].Getscore();	
							percentage = tests[ChoiceTest].Getpercentage();	

							result.push_back(Result(ColvCorrectAnswer, score, percentage, count));
							result[count].PrintRezult();
							
							break;
						}
						cout << "\n������ ������� �����������. ���������� �����." << endl;
						attempts--;
					}
					if (!loggedIn) {
						throw false;
					}
				}
				catch (int) {
					cout << "������ ������������ ���\n";
				}
				catch (bool) {
					cout << "��������� ���������� ������� �����. ���������� �����." << endl;
					return 0;
				}
			} // count > 0
			cout << "\n";	
			break;
		case 2: // �������������
			count++;	
			if (choice == 2) {
				cout << "�������������\n";
				cout << "1 - ������� ������������\n";
				cout << "2 - ������� ������������\n";
				cout << "��� �����: ";
				int adminChoice;
				cin >> adminChoice;
				if (adminChoice == 1) {
					string newFirstName;
					string newLastName;
					string newSurname;
					string newAddress;
					string newPhoneNumber;
					string newPassword;
					string newLogin;

					cout << "������� �������: ";
					cin.ignore();
					getline(cin, newLastName);

					cout << "������� ���: ";
					getline(cin, newFirstName);

					cout << "������� ��������: ";
					getline(cin, newSurname);

					cout << "������� �����: ";
					getline(cin, newAddress);

					cout << "������� ��� ����� �������� (10 ����): ";
					while (true) {
						getline(cin, newPhoneNumber);

						if (newPhoneNumber.size() == 10 && all_of(newPhoneNumber.begin(), newPhoneNumber.end(), isdigit)) {
							break;
						}

						cout << "������������ ����� ��������. ����������, ������� 10 ����: ";
					}

					cout << "������� �����: ";
					getline(cin, newLogin);

					cout << "������� ������: ";
					getline(cin, newPassword);

					users.push_back(User(newFirstName, newLastName, newSurname, newAddress, newPhoneNumber, newPassword, newLogin));

					cout << "������������ ������� ������.\n";
				}
				else if (adminChoice == 2) {
					int userIdToDelete;

					cout << "������� ID ������������ ��� ��������: ";
					cin >> userIdToDelete;

					if (userIdToDelete >= 0 && userIdToDelete < users.size()) {
						users.erase(users.begin() + userIdToDelete);
						cout << "������������ ������� ������.\n";
					}
					else {
						cout << "������������ ID ������������.\n";
					}
				}
			}

			break;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
