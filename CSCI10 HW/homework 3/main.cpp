#include <iostream>

using namespace std;

int main()
{
    int w=0;
    int h=0;
    cout<< "Insert width of rectangle: ";
    cin >> w;
    cout<< "Insert height of rectangle: ";
    cin>> h;
    if ((h>0)&&(w>0)){
    for (int z=0; z<2;z++){
        for (int k=0;k<(w+4); k++){
            cout<< "#";
        }
        cout<< "\n";
    }
    for (int x=0; x<h; x++){
            cout<<"##";
        for (int y=0; y<w; y++){
            cout<< "x";
        }
        cout<<"##";
    cout << "\n";
    }
     for (int z=0; z<2;z++){
        for (int k=0;k<(w+4); k++){
            cout<< "#";
        }
        cout<< "\n";
    }
    }
    else {
        cout<< "Both width and height must be greater than zero.\n";
    }

    cout<<1+4*4;
    return 0;
}
