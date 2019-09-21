#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

set<vector<unsigned>> permutations(unsigned n){
    if(n == 0){
        set<vector<unsigned>> v;
        return v;
    }
    if(n == 1){
        vector<unsigned> v;
        set<vector<unsigned>> s;
        v.push_back(1);
        s.insert(v);
        return s;
    }else{
        set<vector<unsigned>> new_set; //create new empty set you'll return l8r
        set<vector<unsigned>> orig_s = permutations(n-1); //save old set
        for(auto &e: orig_s){
            vector<unsigned> v(e); //copy old set's vector to v
            v.insert(v.begin(),n); //insert new number
            for(unsigned i = 0; i < n; ++i){
                if(i >= 1) //if i > 1 then swap
                swap(v[i-1],v[i]);
                new_set.insert(v);
            }
        }
    return new_set;
    }
}

bool verify(unsigned n){
    size_t c(1);
    for (size_t i = 2; i <= n; ++i)
        c *= i;

    set<vector<unsigned>> p = permutations(n);
    assert(c == p.size());

    for (auto e: p)
    {
        auto t(e);
        assert(t.size() == n);
        sort(t.begin(), t.end());
        for (size_t i = 0; i < t.size(); ++i)
            assert(t[i] == i+1);
    }
    return true;
}

unsigned partition(vector<unsigned> A, int lo, int hi,unsigned &count){
    int i, j;
    for (i = j = lo; j < hi; ++j){
        ++count;
        if (A[j] < A[hi])
            swap(A[j], A[i++]);
    }
    swap(A[i], A[hi]);
    return i;
}

unsigned quick_sort(vector<unsigned> A, int lo, int hi){
    unsigned count = 0;
    if (lo < hi){
        unsigned k = partition(A, lo, hi, count);
        count += quick_sort(A, lo, k-1);
        count += quick_sort(A, k+1, hi);
    }
    return count;
}

set<vector<unsigned>> worst_cases(unsigned n){
    set<vector<unsigned>> empty;
    for(auto &e: permutations(n)){
        vector<unsigned> cpy(e);
        if(((n*(n-1))/2) == quick_sort(cpy,0,n-1))
            empty.insert(e);

    }
    return empty;
}

bool is_heap(vector<unsigned> A, int n, int k){
    int lc = 2*k + 1;
    int rc = 2*k + 2;
    if (lc >= n)
        return true;
    return (A[k] >= A[lc] && is_heap(A, n, lc) &&
            (rc >= n || (A[k] >= A[rc] && is_heap(A, n, rc)))
            );
}
set<vector<unsigned>> heap(unsigned n){
    set<vector<unsigned>> empty;
    for(auto &e: permutations(n)){
        if(is_heap(e,n,0))
            empty.insert(e);
    }
    return empty;
}

int main(){
    /*unsigned n;


    for (unsigned i = 1; i <= 10; ++i)
        verify(i);

    cout << "Passed!" << endl;*/

    unsigned n(10);

    set<vector<unsigned>> my_set(worst_cases(n));
    cout<< "worst cases: ";
    for (auto e: my_set){
        for(auto r: e) cout << r << " ";
        cout <<  endl;
    }
    cout << "number of worst cases: " << my_set.size() << endl;

    set<vector<unsigned>> heap_set(heap(n));
    cout << "heaps: ";
    for(auto e: heap_set){
        for (auto r: e) cout << r << " ";
        cout<< endl;
    }
    cout<< "number of heaps: " << heap_set.size() << endl;

    return 0;
}
