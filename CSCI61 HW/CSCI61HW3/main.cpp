#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

template <class T>
void insertion_sort(T A[], int n){
   if(n < 2){
       return;
   }
   insertion_sort(A, n - 1);
   for(int i = (n-1); (i > 0)&&(A[i] < A[i-1]); --i)
       swap(A[i], A[i-1]);
}

string d2b(unsigned n){
    if(n == 0) return "0";
    string s = d2b(n/2) + to_string(n%2);
    return s;
}
template <class T>
void merge2(T arr[], int start, int mid, int end){
    if ((start >= end)||(start > mid)||(mid>=end)) return;
    if(arr[start] > arr[mid+1]){
        T temp = arr[start];
        arr[start] = arr[mid+1];
        copy(arr + start, arr + mid+1, arr + start + 1);
        arr[start + 1] = temp;
        ++mid;
    }//otherwise arr[start] < arr[mid]
    merge2(arr, (start + 1), mid, end);
}


template <class T>
//pre: sorted arrays A[lo...mid1], A[mid1+1...mid2],A[mid2+1...hi]
//post:: single sorted array
void merge3(T A[], int lo, int mid1, int mid2, int hi){
    merge2(A, lo, mid1, mid2);
    merge2(A, lo, mid2, hi);
}
template <class T>
void merge_sort_3(T A[], int lo, int hi){
    if(lo >= hi) return;
    int n = hi-lo+1;
    int length = n/3;
    if(n == 2){//two elements
        if(A[hi] < A[lo])
            swap(A[lo], A[hi]);
        return;
    }
    else{ //if(lo < hi)
        int mid1 = (lo+length-1);
        int mid2 = (mid1+length);
        merge_sort_3(A, lo, mid1);
        merge_sort_3(A, mid1+1, mid2);
        merge_sort_3(A, mid2+1, hi);
        merge3(A, lo, mid1, mid2, hi);
    }
}

int main(){
    /*
    int N(10000);
        int M(1000);

        for (int c = 1; c <= N; ++c)
        {
            int A[M];

            for (int i = 0; i < M; ++i)
                A[i] = i;

            random_shuffle(A, A+M);
            insertion_sort(A, M);
            assert(is_sorted(A, A+M));
        }

        cout << "Passed!" << endl; //output: Passed!
*/
       unsigned n;

        cout << d2b(0) << endl;
        cout << d2b(1024) << endl;
        cout << d2b(2007) << endl;
        cout << d2b(271828) << endl;
        cout << d2b(141421) << endl;
        //Output: 0
        //010000000000
        //011111010111
        //01000010010111010100
        //0100010100001101101


    int N(10000);
    int M(1000);

    for (int c = 1; c <= N; ++c)
    {
        int A[M];

        for (int i = 0; i < M; ++i)
            A[i] = i;

        random_shuffle(A, A+M);
        merge_sort_3(A, 0, M-1);
        assert(is_sorted(A, A+M));
    }

    cout << "Passed!" << endl;

    return 0;
}


