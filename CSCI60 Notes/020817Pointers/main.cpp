#include <iostream>
//POINTERS ARE BASICALLY ARRAY INDEXES!!

using namespace std;

int main()
{
    int A[3]={4, 5, 6};
    int i = 2;

    A[i]; //i is an index of an element in A.
    //A[i] is the value at that index
    //pointers are i's and A[] is memory.

    int a = 5;
    int b = 7;
    int c = 1112;
    //if you want the address of a, b, and c you use:
    cout << &a << endl << &b << endl << &c << endl;

    auto p = &a; //a thing that holds an address in memory is a pointer
    //going from index to value -> i to A[i]

    //if you wanted to go from A[i] to i is:
    cout<< *p <<endl;
    //if you changed the value of the pointer, the value changes as well
    // *p = 9;
    //values: a = 9, *p = 9.

    //the address of a variable will not change while the value of the variable changes.
    // p has an address even though it does not hold a value
    //value of pointers and their objects:
    //p = &b;
    //*p = b;

    //if you have a pointer to a pointer and want the object, use **p.
    // for example, q is a pointer to p, and p is a pointer to int 4.
    //**q = 4;
    //cannot && because we can't take an address of a number; can only take
    //the address of a variable.

    //a[0] means the exact same as *a
    //A[k] = *(A+k)

    //arrays are short-hand notations to point to locations of memory like pointers.
    //the only difference is that arrays look at a number of contiguous info

    int* p = nullptr; //will make the program crash if we try to dereference an
    //unreferenced value
    return 0;
}
