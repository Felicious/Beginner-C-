#include <iostream>

using namespace std;

void weird(int &a, int &b, int &c);
void strange(int a, int &b);

int main() {
    int x = 3;
    int y = 11;
    int z = 7;
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    weird(x, y, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    strange(x, y);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    weird(y, y, y);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    strange(z, z);
    cout << "x = " << x << ", y = " << y << ", z = " << z << endl;
    return 0;
}

void weird(int &a, int &b, int &c) {
    int  temp = a;
    a = b;
    b = c;
    c = temp;
}

void strange(int a, int &b) {
    a *= 2;
    b *= 2;
    int temp = b;
    b = a;
    a = temp;
}
