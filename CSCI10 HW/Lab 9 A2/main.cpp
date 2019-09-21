#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
double average(double arr[], int size);
int main()
{
    ifstream in_file;
    ofstream out_file;
    int count = 0;
    double scores[200];
    in_file.open("psych-round2-scores.txt");
    out_file.open("outlab9.txt");
    if(in_file.fail()){
        cout << "Input file opening failed \n";
        exit(1);
    }
    while (in_file>>scores[count]){
        count++;
    }
    double avg = average(scores, count);
    out_file << avg;
    for (int i = 0; i < count; i++){
        if (scores[i] > avg){
            out_file << scores[i];
            out_file << endl;
        }
    }
    in_file.close();
    out_file.close();
    return 0;
}
double average(double arr[], int size){
    double total=0;
    for(int i=0; i<size; i++){
        total=total+arr[i];
    }
    return total/size;
}
