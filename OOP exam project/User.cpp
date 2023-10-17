#include "User.h"
User::User(string first, string last, string sur, string addr, string phone, string pass, string log) :
    firstname(first), lastname(last), surname(sur),
    address(addr), phoneNumber(phone), password(pass), login(log) {
    // Вы также можете добавить дополнительный код инициализации, если это необходимо.
}

string User::GetFirstname() const {
    return firstname;
}

string User::GetLastname() const {
    return lastname;
}

string User::GetSurname() const {
    return surname;
}

string User::GetAddress() const {
    return address;
}

string User::GetPhoneNumber() const {
    return phoneNumber;
}

string User::GetPassword() const
{
    return password;
}

string User::GetLogin() const
{
    return login;
}

//{
//    cout << "Количество правильных ответов: " << ColvCorrectAnswer << endl;
//    cout << "Процент правильных ответов: " << percentage << "%" << endl;
//    cout << "Оценка за пройденный тест: " << score << endl;
//}
//
//void User::AddCompletedTest(int testId) {
//    completedTests.push_back(testId);
//}
