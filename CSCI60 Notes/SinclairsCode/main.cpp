#include <vector>
#include <iostream>
#include <numeric>
#include <chrono>

/**
 * merge
 *
 * This function assumes that the values
 *     vec[start], vec[start+1], ..., vec[mid-1]
 * are in sorted order, and that values
 *     vec[mid], vec[mid+1], ..., vec[end-1]
 * are in sorted order. This function merges both halves into a sorted vector.
 *
 */
template<typename T, typename S>
void merge(std::vector<T>& vec, S start, S mid, S end) {
    // We will use a temp vector to hold our merged vector
    std::vector<T> temp;
    temp.reserve(end - start);

    // Declare two index variables, one for each half of the list
    S i = start, j = mid;
    // Loop while both indexes are still in their valid range
    while (i < mid && j < end) {
        // Determine which half has the smaller value
        if (vec.at(i) < vec.at(j)) {
            // Add item and increment index
            temp.push_back(vec.at(i++));
        } else {
            // Add item and increment index
            temp.push_back(vec.at(j++));
        }
    }

    // If there are values left in first half, add them to temp.
    for (; i < mid; ++i) temp.push_back(vec.at(i));
    // If there are values left in second half, and them to temp.
    for (; j < end; ++j) temp.push_back(vec.at(j));

    // Copy temp vector back over to vec
    for (S k = 0; k < temp.size(); ++k) vec.at(start+k) = temp.at(k);
}

template<typename T, typename S>
void merge_sort(std::vector<T>& vec, S start, S mid, S end) {
    if (vec.size() <= 1 || end - start <= 1)
        return;

    // Step 2: Recursively use merge_sort to sort the first half of the vector,
    //                 i.e, the values vec[start], vec[start+1], ..., vec[mid-1].
    merge_sort(vec, start, (start + mid)/2, mid);

    // Step 3: Recursively use merge_sort to sort the second half of the vector,
    //                 i.e., the values vec[mid], vec[mid+1], ..., vec[end-1].
    merge_sort(vec, mid, (mid + end)/2, end);

    // Step 4: Use the merge function to merge the two sorted halves of vec.
    merge(vec, start, mid, end);

}


int main() {
    using std::cout;
    using std::endl;
    using namespace std::chrono;

    std::vector<int> a = {8, 4, 1, 6, 9, 3};
    int n = a.size();
    merge_sort(a, 0, n / 2, n);
    for (auto e : a) cout << e << " ";
    cout << endl << endl;

    for (int sz = 1; sz <= 10000000; sz *= 10)
    {
        std::vector<int> b;
        for (int j = 0; j < sz; j++)
        {
            b.push_back(-j);
        }

        int k = b.size();
        auto start = high_resolution_clock::now();
        merge_sort<int, int>(b, 0, k/2, k);
        auto end = high_resolution_clock::now();
        duration<double, std::milli> d = end - start;
        std::cout << k << ": " << d.count() << "ms" << std::endl;
    }
    return 0;
}
