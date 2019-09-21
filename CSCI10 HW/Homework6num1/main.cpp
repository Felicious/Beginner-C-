#include <iostream>

using namespace std;

int find_value(int A[], int sz, int value);
int main()
{
    int A[] = {10,45,12,44,20,17,23,8,9};
    cout << find_value(A, 6 , 20);
    return 0;
}

int find_value(int A[], int sz, int value){
    int i;
    for (i=0; i < sz; i++){
        if (value == A[i]){
            break;
        }
    }
    return i;
}
