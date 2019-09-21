#include <iostream>

using namespace std;

int main()
{
    string m;
    string f;
    cout << "What is your mother's genotype?" << endl;
    cin >> m;
    cout << "What is your father's genotype?" << endl;
    cin >> f;
    if (((m=="GG") && (f=="gg")) || ((f=="GG") && (m=="gg"))) {
        cout << "Your genotype is Gg." << endl;
    }
    else if (((m=="Gg")&&(f=="GG"))||((f=="Gg")&&(m=="GG"))) {
        cout << "There is a 50% chance your genotype is GG and 50% chance that it is Gg." << endl;
    }
    else if (((m=="Gg")&&(f=="gg"))||((f=="Gg")&&(m=="gg"))) {
        cout << "There is a 50% chance your genotype is Gg and 50% chance that it is gg." << endl;
    }
    else if (((m=="Gg")&&(f=="Gg"))||((f=="Gg")&&(m=="Gg"))) {
        cout << "You have a 50% chance your genotype is Gg, 25% chance that it's GG, and 25% chance it is gg." << endl;
    }
    else if (((m=="GG")&&(f=="GG"))||((f=="GG")&&(f=="GG"))) {
        cout << "Your genotype is GG." << endl;
    }
    else if (((m=="gg") && (f=="gg"))||((f=="gg") && (m=="gg"))) {
        cout << "Your genotype is gg." << endl;
    }
    else
        cout << "what... stop playin'!\n";
    return 0;
}
