#include <iostream>
using namespace std;

int main()
{
 int quizzes=0;
 double quiz_score=0;
 double sum=0;
 double class_average=0;
 cout<< "Enter total number of quizzes: " << endl;
 cin >> quizzes;
 for (int x=0; x<quizzes; x++) {
    cout<< "Enter score for quiz "<<(x+1)<<": " << endl;
    cin >> quiz_score;
    sum= sum+quiz_score;
 }
class_average=(sum)/(quizzes);
cout << "The quiz average for the class is: " <<class_average << endl;

return 0;
}
