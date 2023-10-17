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
		tests.push_back(Test("Математика", 1, 1, 6, "Элементарная математика", 2 ,count));	

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

				cout << "Введите Фамилию: ";
				cin.ignore();	
				getline(cin, userFirstname);


				cout << "Введите имя: ";
				cin.ignore();
				getline(cin, userLastname);

				cout << "Введите отчество: ";
				cin.ignore();
				getline(cin, userSurname);

				cout << "Введите ваш адрес: ";
				getline(cin, userAddress);
				 
				cout << "Введите ваш номер телефона (10 цифр): ";
				while (true) {
					getline(cin, userPhoneNumber);

					if (userPhoneNumber.size() == 10 && all_of(userPhoneNumber.begin(), userPhoneNumber.end(), isdigit)) {
						break;
					}

					cout << "Некорректный номер телефона. Пожалуйста, введите 10 цифр: ";
				}

				cout << "Введите ваш пароль: ";
				cin >> userPasword;

				cout << "Введите ваш логин: ";
				cin >> userLogin;

				system("cls");
				cout << "Регистрация успешно завершена\n";
				Sleep(2000);
				system("cls");
				users.push_back(User(userFirstname, userLastname, userSurname, userAddress, userPhoneNumber, userPasword, userLogin));
	
				system("cls");
				int ChoiceTest;
				cout << "ВЫБИРИТЕ РАЗДЕЛ ДЛЯ ПРОХОЖДЕНИЯ ТЕСТА\n";

				for (int i = 0; i < tests.size(); i++) {
					cout << i << ". " << tests[i].GetName() << endl;
				}

				cout << "Ваш выбор: ";
				cin >> ChoiceTest;
				tests[ChoiceTest].ChoiceChapt();

				ColvCorrectAnswer = tests[ChoiceTest].GetColvCorrectAnswer();	
				score = tests[ChoiceTest].Getscore();
				percentage = tests[ChoiceTest].Getpercentage();

				result.push_back(Result(ColvCorrectAnswer, score, percentage, count));	
				result[count].PrintRezult();	

			}
			else { // count > 0
				cout << "ВЫБЕРИТЕ УЧЁТНУЮ ЗАПИСЬ\n";
				for (int i = 0; i < users.size(); i++) {
					cout << i << ". " << users[i].GetFirstname() << endl;
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

							ColvCorrectAnswer = tests[ChoiceTest].GetColvCorrectAnswer();	
							score = tests[ChoiceTest].Getscore();	
							percentage = tests[ChoiceTest].Getpercentage();	

							result.push_back(Result(ColvCorrectAnswer, score, percentage, count));
							result[count].PrintRezult();
							
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
			cout << "\n";	
			break;
		case 2: // Администратор
			count++;	
			if (choice == 2) {
				cout << "АДМИНИСТРАТОР\n";
				cout << "1 - Создать пользователя\n";
				cout << "2 - Удалить пользователя\n";
				cout << "Ваш выбор: ";
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

					cout << "Введите Фамилию: ";
					cin.ignore();
					getline(cin, newLastName);

					cout << "Введите Имя: ";
					getline(cin, newFirstName);

					cout << "Введите Отчество: ";
					getline(cin, newSurname);

					cout << "Введите адрес: ";
					getline(cin, newAddress);

					cout << "Введите ваш номер телефона (10 цифр): ";
					while (true) {
						getline(cin, newPhoneNumber);

						if (newPhoneNumber.size() == 10 && all_of(newPhoneNumber.begin(), newPhoneNumber.end(), isdigit)) {
							break;
						}

						cout << "Некорректный номер телефона. Пожалуйста, введите 10 цифр: ";
					}

					cout << "Введите логин: ";
					getline(cin, newLogin);

					cout << "Введите пароль: ";
					getline(cin, newPassword);

					users.push_back(User(newFirstName, newLastName, newSurname, newAddress, newPhoneNumber, newPassword, newLogin));

					cout << "Пользователь успешно создан.\n";
				}
				else if (adminChoice == 2) {
					int userIdToDelete;

					cout << "Введите ID пользователя для удаления: ";
					cin >> userIdToDelete;

					if (userIdToDelete >= 0 && userIdToDelete < users.size()) {
						users.erase(users.begin() + userIdToDelete);
						cout << "Пользователь успешно удален.\n";
					}
					else {
						cout << "Некорректный ID пользователя.\n";
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
