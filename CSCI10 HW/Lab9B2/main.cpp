#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;
struct StudentInfo{
    string fname;
    string lname;
    string classlevel;
    double gpa;
};

int main()
{
    ifstream in_file;
    in_file.open("studentlist1.txt");
    StudentInfo students[100];
    int count = 0;
    while(in_file >> students[count].fname){
        in_file >> students[count].lname;
        in_file >> students[count].classlevel;
        in_file >> students [count].gpa;
        count ++;
    }
    for (int i = 0; i < count; i++){
        cout << students[i].fname << " " << students[i].lname << endl;
        cout << students[i].classlevel << endl << students[i].gpa << endl;
    }
    in_file.close();
    return 0;
}
