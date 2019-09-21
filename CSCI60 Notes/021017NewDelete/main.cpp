#include <iostream>

using namespace std;

//can't return arrays, but u can return a pointer.
int* push_back(int* data, size_t size, size_t capacity, int value){
    if( size == capacity){
        //make more room
        capacity *= 2; //doubling size of an array will decrease run time
        int* new_arr_ptr = new int[capacity]; // create a new array, one bigger
        for (size_t i = 0; i < size; i++){
            new_arr_ptr[i] = data[i]; //copies old array into new one
        }
        delete[] data; //delete old array
        data = new_arr_ptr;
    }
    data[size++] = value;
    return data;
}

int main()
{
    //int* p = nullptr
    //p = new int[1000];
    //for (int i = 0; i <1000; i++) p[i] = 0;
    //cout << "End" << endl;
    //does alot of crap and you have wasted alot of memory.

    //should free up memory into the "heap"
    //delete[]p;
    //this deletes the value of the pointer so it no longer points to the now empty
    //block of memory

    //"dangling pointers" are pointers that still point to empty parts of memory
    //avoid problem by setting
    //p = nullptr;
    //after you use delete[]p.

    //deleting twice is undefined behavior and it's horrible bc u can delete other
    //ppl's code.
    //however, deleting a null pointer doesn't do anyhting so ur cool; its a null operation

    //componets of arrays: data, capacity, size
    int* data = nullptr; //asterisk indicates data is a pointer
    size_t capacity = 16;
    size_t size = 0;

    data = new int[capacity]; //dont need to initialize array cells to zero
    //this is because you're never reading into parts of an array u didn't write into yet
    //setting equal to 0 is wasting time.

    int value = 0;
    cin >> value;
    data = push_back(data, size, capacity, value);
    return 0;
}
