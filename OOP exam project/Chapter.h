#pragma once
#include <string>
#include "Question.h"
#include "deque"  
#include <windows.h>
using namespace std;

class Chapter
{
private:    
    int idChapter;
    int NumberQuestions;
    int ColvoCorrectAnswer;
    int ScorePlus;
    int ScoreTestChapt;  
    string nameChapter; 
    deque<Question> quest;  

public:
    Chapter() = default;
    Chapter(int id, int numb, string nc, int sc);   
    void DefaultQustions(); 
    void StartTest();
    int GetNumberQuestions() const;
    string GetNameChapt() const;     
    int GetColvoCorrectAnswer() const;  
    int GetScoreTestChapt() const;
    int GetScorePlus() const;     
    void SetColvoCorrectAnswer(int zero); 
};  