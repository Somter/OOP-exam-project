#include "User.h"

User::User(string fio, string addr, string phone, string pass, string log)
    : FIO(fio), address(addr), PhoneNumber(phone), password(pass), login(log) {}    

string User::GetFio() const {
    return FIO;
}

string User::GetPassword() const {
    return password;
}

string User::GetLogin() const {
    return login;
}

void User::AddCompletedTest(int testId) {
    completedTests.push_back(testId);
}

void User::AddTestResult(Result result) {
    testResults.push_back(result);
}