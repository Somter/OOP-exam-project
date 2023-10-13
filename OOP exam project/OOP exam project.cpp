// OOP exam project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <deque> 
#include <windows.h>	
#include "User.h"
#include "Test.h"	
using namespace std;

int main() { 
	setlocale(LC_ALL, "");
	deque<User> users;	
	deque<Test> tests;			
	

	//for (auto it = users.begin(); it != users.end(); ++it) {
	//	it->Print();
	//	cout << endl;
	//}

	string FIO, address, PnoneNumber, pasword, login;	
	int choice, count = 0, ChoiceAccaunt;
	while (true) {	
		cout << "Выбирите режим: \n";
		cout << "1 - Тестируемый\n";
		cout << "2 - Администратор\n";
		cout << "Ваш быбор: ";
		cin >> choice; // выбор режима
		system("cls");
		switch (choice) {
		case 1:	// Тестируемый			
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
			}
			else { // count > 0
				cout << "ВЫБЕРИТЕ УЧЁТНУЮ ЗАПИСЬ\n"; 
				for (int i = 0; i < users.size(); i++) {
					cout << i << ". " << users[i].GetFio() << endl;
				}

				cout << "Ваш выбор: "; // выбор аккаунта
				try {
					cin >> ChoiceAccaunt;
					if (ChoiceAccaunt > users.size()) {
						throw 1;
					}

				}
				catch (int) { 
					cout << "Такого пользователя нет\n";
				}
				
			} // count > 0


			count++;	
			break;
		case 2: // Администратор	
		/*	users.push_back(User(FIO, address, PnoneNumber, pasword, login));	
		for (auto it = users.begin(); it != users.end(); ++it) {
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
