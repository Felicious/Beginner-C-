#include <iostream>

using namespace std;
struct Date{
    int month;
    int day;
    int year;
};
struct Item{
    string name;
    string autart;
    double price;
    string chaptrack[50];
    int sz;
    Date release;
};

double fillCart(Item a[], int size);
int main()
{
 Item amazon[3] = {{"Slaughterhouse 5", "Kurt Vonnegut", 7.99},
    {"Let it Be", "The Replacements", 11.49,{"I Will Dare", "Favorite Thing", "We're Comin' Out",
            "Tommy Gets His Tonsils Out","Androgynous","Black Diamond","Unsatisfied",
            "Seen Your Video","Gary's Got","Sixteen Blue","Answering Machine"}, 11, {10, 2, 1984}},
    {"Let it Be", "The Beatles", 16.29, {"Two Of Us", "Dig A Pony","Across The Universe",
            "I Me Mine","Dig It","Let It Be","Maggie Mae","I've Got A Feeling","One After 909",
            "The Long And Winding Road","For You Blue","Get Back"}, 12, {5, 11, 1970}}};

    cout<<"Total cost: "<<fillCart(amazon, 3);

    return 0;
}
void printItem(Item it){
    cout << "Item name: " << it.name << endl;
    cout << "Item's author/artist: " << it.autart << endl;
    cout << "Item's price: $" << it.price << endl;
    cout << "Item's chapters/tracks: " << endl;
    for (int i = 0; i < it.sz; i++){
         cout << it.chaptrack[i] << endl;
    }
    cout << "Item's release date: " << it.release.month << "/" << it.release.day << "/" << it.release.year << endl;
}
double fillCart(Item a[], int size){
    double total = 0;
    for (int i = 0; i<3; i++){
    string input = "";
    cout<<"Item: "<<a[i].name<<", by "<<a[i].autart<<" for "<<a[i].price<<".\n";
    cout<<"Would you like to \"purchase\", \"pass\", or see more \"details?\"\n";
    cin>>input;
    if (input == "purchase"){
        total+=a[i].price;
    }else if (input == "details"){
        printItem(a[i]);
        cout<<"Would you like to \"purchase\" or \"pass\"?\n";
            cin>>input;
            if (input == "purchase"){
                total+=a[i].price;
            }
    }
}
return total;
}


