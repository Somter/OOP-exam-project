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
using namespace std;

int main() {
	setlocale(LC_ALL, "");
	deque<User> users;
	deque<Test> tests;

	string FIO, address, PnoneNumber, pasword, login;
	int choice, count = 0, ChoiceAccaunt, ChoiceTest;	
	string CheckPaword, CheckLogin;
	while (true) {
		tests.push_back(Test("����������", 1, 1, 6, "������������ ����������", 2, count));	

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

				cout << "������� ���� ���: ";
				cin.ignore();
				getline(cin, FIO);

				cout << "������� ��� �����: ";
				getline(cin, address);
				 
				cout << "������� ��� ����� ��������: "; 
				getline(cin, PnoneNumber);

				cout << "������� ��� ������: ";
				cin >> pasword;

				cout << "������� ��� �����: ";
				cin >> login;
				system("cls");
				cout << "����������� ������� ���������\n";
				Sleep(2000);
				system("cls");
				users.push_back(User(FIO, address, PnoneNumber, pasword, login));
	
				system("cls");
				int ChoiceTest;
				cout << "�������� ������ ��� ����������� �����\n";
				for (int i = 0; i < tests.size(); i++) {
					cout << i << ". " << tests[i].GetName() << endl;
				}
				cout << "��� �����: ";
				cin >> ChoiceTest;
				tests[ChoiceTest].ChoiceChapt();
				system("cls");

			}
			else { // count > 0
				cout << "�������� �ר���� ������\n";
				for (int i = 0; i < users.size(); i++) {
					cout << i << ". " << users[i].GetFio() << endl;
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

			// 2. ����
			
			cout << "\n";	
			count++;
			break;
		case 2: // �������������
		users.push_back(User("Luffi", "2", "3", "4", "5"));
	/*	for (auto it = users.begin(); it != users.end(); ++it) {
			it->Print();
			cout << endl;

		}*/
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
