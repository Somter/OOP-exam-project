#include "Chapter.h"

Chapter::Chapter(int id, int numb, string nc, int sc)   
{
    idChapter = id;
    NumberQuestions = numb;
    nameChapter = nc;   
    ColvoCorrectAnswer = 0; 
    ScorePlus = 0;  
    ScoreTestChapt = sc;    
}

void Chapter::DefaultQustions()
{
    quest.push_back(Question("1 + 1", "1) 3", "2) 17", "3) 2", 1, 2, ScoreTestChapt));
    quest.push_back(Question("3 - 2", "1) 0", "2) 1", "3) 100", 2, 1, ScoreTestChapt));
    quest.push_back(Question("10 + 12", "1) 58", "2) 142", "3) 22", 3, 22, ScoreTestChapt));
    quest.push_back(Question("3 * 3", "1) 9", "2) 99", "3) 6", 4, 9, ScoreTestChapt));
    quest.push_back(Question("20 / 2", "1) 13", "2) 10", "3) 2", 5, 10, ScoreTestChapt));   
    quest.push_back(Question("100 + 120", "1) 300", "2) 221", "3) 220", 6, 220, ScoreTestChapt));   
}

void Chapter::StartTest()
{
    int YourAnswer;  
    for (int i = 0; i < quest.size(); i++)  
    {
            system("cls");  
        	cout << "Вопрос: " << quest[i].GetQustion();
            cout << "\n----------------------\n";
        	cout << quest[i].GetFirstOption() << endl;
        	cout << quest[i].GetSecondOption() << endl; 
        	cout << quest[i].GetThirdOption() << endl;  
        	cout << "Ваш ответ: ";
        	cin >> YourAnswer;	
            
            if (YourAnswer == quest[i].GetCorrectAnswer()) {       
                ColvoCorrectAnswer++;
                ScorePlus += ScoreTestChapt;    
                system("cls");
                cout << "Верно!\n"; 
                Sleep(1300);        
            }
            else {
                system("cls");
                cout << "Неверно (\n";  
                Sleep(1300);    
            }

    }
}

int Chapter::GetNumberQuestions() const {
    return NumberQuestions;
}

string Chapter::GetNameChapt() const        
{
    return nameChapter; 
}

int Chapter::GetColvoCorrectAnswer() const
{
    return ColvoCorrectAnswer;  
}

int Chapter::GetScoreTestChapt() const  
{
    return ScoreTestChapt;  
}

int Chapter::GetScorePlus() const
{
    return ScorePlus;   
}

