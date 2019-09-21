#include <iostream>

using namespace std;
struct Matrix{
int a[3];
int b[3];
int c[3];
};
void printMatrix(Matrix m);
Matrix sum(Matrix mats[], int size);
int main()
{
    int size = 4;
    Matrix mats[size] = {{
    {1,2,3},
    {4,5,6},
    {7,8,9}
    },{
    {9,8,7},
    {6,5,4},
    {3,2,1}
    },{
    {4,4,4},
    {4,4,4},
    {4,4,4}
    },{
    {6,6,6},
    {6,6,6},
    {6,6,6}
    }};
    Matrix x = sum(mats,4);
    printMatrix(x);
    return 0;
}
void printMatrix(Matrix m){
    for (int i = 0; i < 3; i++){
        cout<<m.a[i]<<" ";
    }
    cout<<endl;
    for (int j = 0; j < 3; j++){
        cout<<m.b[j]<<" ";
    }
    cout<<endl;
    for (int k = 0; k < 3; k++){
        cout<<m.c[k]<<" ";
    }
    cout<<endl;
}
Matrix sum(Matrix mats[], int size){
    Matrix sum = {{0,0,0},{0,0,0},{0,0,0}};
    for (int i =0; i < size; i++){
        for (int j = 0; j < size; j++){
            sum.a[i] += mats[j].a[i];
        }
    }
    for (int k = 0; k < size; k++){
        for (int j = 0; j < size; j++){
            sum.b[k] += mats[j].b[k];
        }
    }
    for (int l = 0; l < size; l++){
        for (int j = 0; j < size; j++){
            sum.c[l] += mats[j].c[l];
        }
    }
    return sum;
}
