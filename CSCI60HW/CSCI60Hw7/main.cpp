#include <iostream>
#include <chrono>
#include <random>

using namespace std;
void populate(int arr[], int sz);
void merge(int arr[], int start, int mid, int end);
void mergesort(int arr[], int start, int end);

int main()
{
    //const int size = 100;
    //const int size = 1000;
    const int size = 10000;
    int arr[size];
    populate(arr,size);
    auto start = std::chrono::high_resolution_clock::now();
    mergesort(arr, 0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> run = end - start;
    std::cout << std::endl;
    std::cout << run.count() << " milliseconds" << std::endl;

    return 0;
}
void populate(int arr[], int sz){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> ud(-6774, 8646);
    for(int i = 0; i < sz; ++i) arr[i] = ud(gen);
}

void merge(int arr[], int start, int mid, int end){
    if ((start >= end)||(start > mid)||(mid>=end)) return;
    if(arr[start] > arr[mid+1]){
        int temp = arr[start];
        arr[start] = arr[mid+1];
        std::copy(arr + start, arr + mid+1, arr + start + 1);
        arr[start + 1] = temp;

        ++mid;
    }//otherwise arr[start] < arr[mid]
    merge(arr, start + 1, mid, end);
}

void mergesort(int arr[], int start, int end){
    if(start < end){
        int mid = (start + end)/2;
        mergesort(arr, start, mid);
        mergesort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

