#pragma once
#include <iostream>
#include <string>
using namespace std;	
class Result{
private:
    int ColvCorrectAnswer;
    int score;
    double percentage;
    int testId; // Идентификатор теста

public:
    Result(int cca, int sc, double per, int id);    

    int GetColvCorrectAnswer() const;
    int GetScore() const;
    double GetPercentage() const;

    void PrintRezult();

    // Метод для установки идентификатора теста
    //void SetTestId(int id);
};
