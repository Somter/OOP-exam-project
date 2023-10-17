#include "User.h"
User::User(string first, string last, string sur, string addr, string phone, string pass, string log) :
    firstname(first), lastname(last), surname(sur),
    address(addr), phoneNumber(phone), password(pass), login(log) {
    // �� ����� ������ �������� �������������� ��� �������������, ���� ��� ����������.
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
//    cout << "���������� ���������� �������: " << ColvCorrectAnswer << endl;
//    cout << "������� ���������� �������: " << percentage << "%" << endl;
//    cout << "������ �� ���������� ����: " << score << endl;
//}
//
//void User::AddCompletedTest(int testId) {
//    completedTests.push_back(testId);
//}
