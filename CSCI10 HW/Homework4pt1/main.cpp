#include <iostream>

using namespace std;
 int f(int a, int b);
int g(int x, int y);
int h(int a, int b);

int main() {
    int a = 1;
    int b = 2;
    int c = 3;

    a = f(a, b);
    cout << a << endl;
    cout << b << endl;

    b = g(a, c);
    cout << b << endl;
    cout << c << endl;

    c = h(a++, b+c);
    cout << c << endl;
    cout << a << endl;

    return 0;
}

int f(int a, int b){
    a += b;
    return a + b;
}

int g(int x, int y){
    x++;
    return y;
}

int h(int a, int b) {
    return f(a, a) * g(b, b);
}
