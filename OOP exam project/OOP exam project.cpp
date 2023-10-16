// OOP exam project.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <deque>
#include <windows.h>	
#include "User.h"
#include "Test.h"
#include "Question.h"
#include "Chapter.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "");
	deque<User> users;
	deque<Test> tests;

	tests.push_back(Test("Математика", 1, 1, 6, "Элементарная математика", 2));	

	string FIO, address, PnoneNumber, pasword, login;
	int choice, count = 0, ChoiceAccaunt, ChoiceTest;	
	string CheckPaword, CheckLogin;
	while (true) {
		cout << "Выбирите режим: \n";
		cout << "1 - Тестируемый\n";
		cout << "2 - Администратор\n";
		cout << "Ваш быбор: ";
		cin >> choice; // выбор режима
		system("cls");
		switch (choice) {
		case 1:	// Тестируемый	

			// 1. РЕГИСТРАЦИЯ  
			
			if (count == 0) {
				cout << "РЕГИСТРАЦИЯ\n";

				cout << "Введите ваше ФИО: ";
				cin.ignore();
				getline(cin, FIO);

				cout << "Введите ваш адрес: ";
				getline(cin, address);
				 
				cout << "Введите ваш номер телефона: "; 
				getline(cin, PnoneNumber);

				cout << "Введите ваш пароль: ";
				cin >> pasword;

				cout << "Введите ваш логин: ";
				cin >> login;
				system("cls");
				cout << "Регистрация успешно завершена\n";
				Sleep(2000);
				system("cls");
				users.push_back(User(FIO, address, PnoneNumber, pasword, login));

				system("cls");
				int ChoiceTest;
				cout << "ВЫБИРИТЕ РАЗДЕЛ ДЛЯ ПРОХОЖДЕНИЯ ТЕСТА\n";
				for (int i = 0; i < tests.size(); i++) {
					cout << i << ". " << tests[i].GetName() << endl;
				}
				cout << "Ваш выбор: ";
				cin >> ChoiceTest;
				tests[ChoiceTest].ChoiceChapt();
				//system("cls");

			}
			else { // count > 0
				cout << "ВЫБЕРИТЕ УЧЁТНУЮ ЗАПИСЬ\n";
				for (int i = 0; i < users.size(); i++) {
					cout << i << ". " << users[i].GetFio() << endl;
				}
				int ChoiceAccaunt;
				cout << "Ваш выбор: ";

				try {
					cin >> ChoiceAccaunt;
					if (ChoiceAccaunt >= users.size() || ChoiceAccaunt < 0) {
						throw 1;
					}

					bool loggedIn = false;
					int attempts = 3;

					while (attempts > 0) {

						cout << "Пароль: ";
						string CheckPassword;
						cin >> CheckPassword;
						cout << "Логин: ";
						string CheckLogin;
						cin >> CheckLogin;

						if (CheckPassword == users[ChoiceAccaunt].GetPassword() && CheckLogin == users[ChoiceAccaunt].GetLogin()) {

							tests.push_back(Test("Математика", 1, 1, 6, "Элементарная математика", 2));
							loggedIn = true;	
							system("cls");	
							int ChoiceTest;
							cout << "ВЫБИРИТЕ РАЗДЕЛ ДЛЯ ПРОХОЖДЕНИЯ ТЕСТА\n";
							for (int i = 0; i < tests.size(); i++) {
								cout << i << ". " << tests[i].GetName() << endl;
							}
							cout << "Ваш выбор: ";
							cin >> ChoiceTest;
							system("cls");
							tests[ChoiceTest].ChoiceChapt();
							
							break;
						}
						cout << "\nДанные указаны неправильно. Попробуйте снова." << endl;
						attempts--;
					}
					if (!loggedIn) {
						throw false;
					}
				}
				catch (int) {
					cout << "Такого пользователя нет\n";
				}
				catch (bool) {
					cout << "Превышено количество попыток входа. Попробуйте позже." << endl;
					return 0;
				}
			} // count > 0

			// 2. Тесе
			
			cout << "\n";	
			count++;
			break;
		case 2: // Администратор
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
