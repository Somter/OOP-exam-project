#include <iostream>
#include "Result.h"

Result::Result(int cca, int sc, double per, int id) 
    : ColvCorrectAnswer(cca), score(sc), percentage(per), testId(id) {}

int Result::GetColvCorrectAnswer() const {
    return ColvCorrectAnswer;
}

int Result::GetScore() const {
    return score;
}

double Result::GetPercentage() const {
    return percentage;
}
void Result::PrintRezult()
{
    cout << "���������� ���������� �������: " << ColvCorrectAnswer << endl;
    cout << "������� ���������� �������: " << percentage << "%" << endl;
    cout << "������ �� ���������� ����: " << score << endl;
}
//
//void Result::SetTestId(int id) {
//    testId = id;
//}