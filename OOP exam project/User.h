#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Result.h"

class User {
private:
    string firstname;   
    string lastname;  
    string surname;
    string address; 
    string phoneNumber;
    string password;
    string login;
  //  vector<int> completedTests; 
   // vector<Result> testResults; 

public:
    User(string firstname, string lastname, string surname, string addr, string phone, string pass, string log);
    string GetFirstname() const;
    string GetLastname() const;
    string GetSurname() const;
    string GetAddress() const;
    string GetPhoneNumber() const;
    string GetPassword() const;
    string GetLogin() const;

  /*  void SetColvCorrectAnswer(int answer);
    void SetScore(int scr);
    void Setpercentage(int perc);

    int GetColvCorrectAnswer();
    int GetScore();
    int Getpercentage();

    void PrintRezult();*/ 

   
 
};

