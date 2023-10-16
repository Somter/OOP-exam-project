#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Result.h"

class User {
private:
    string FIO;
    string address;
    string PhoneNumber;
    string password;
    string login;
    vector<int> completedTests; 
    vector<Result> testResults; 

public:
    User(string fio, string addr, string phone, string pass, string log);

    string GetFio() const;
    string GetPassword() const;
    string GetLogin() const;

    void AddCompletedTest(int testId);
 
};

