#include <bits/stdc++.h>
using namespace std;

// demonstrates the use of some useful STL functions

template <typename T>
void printvec(const vector<T>& v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}

void stl_sort() {
    vector<int> v = {1, 3, 2, 5, 4};

    cout << "sort in ascending order: ";
    sort(v.begin(), v.end());
    printvec(v);

    cout << "sort in descending order: ";
    sort(v.begin(), v.end(), greater<int>());
    printvec(v);

    v = {11, 23, 45, 90, 22};
    // demo of lambda function for custom sorting
    cout << "sort by last digit: ";
    sort(v.begin(), v.end(), [](int a, int b) { return a % 10 < b % 10; });
    printvec(v);
}

void stl_accumulate() {
    vector<int> v = {1, 2, 3, 4, 5};

    int sum = accumulate(v.begin(), v.end(), 0);  // 0 is the initial value
    cout << "sum of all elements: " << sum << endl;
}

void stl_binary_search() {
    vector<int> v = {1, 2, 3, 4, 5};

    // return true if the element is present in a sorted vector
    cout << "is 6 present in [1,2,3,4,5] ? "
         << binary_search(v.begin(), v.end(), 6) << endl;
    cout << "is 3 present in [1,2,3,4,5] ? "
         << binary_search(v.begin(), v.end(), 3) << endl;
}

void erase_element() {
    vector<int> v = {1, 2, 3, 4, 5};

    // erase the element at index 2 (val = 3)
    cout << "erasing element at index 2: ";
    v.erase(v.begin() + 2);
    printvec(v);

    // erase the element with value 4
    // find the index (iterator) of the element
    cout << "erasing element with value 4: ";
    vector<int>::iterator pos = find(v.begin(), v.end(), 4);
    // erase the element at the iterator
    v.erase(pos);
    printvec(v);
}

void next_permutation() {
    vector<char> v = {'a', 'a', 'b'};
    next_permutation(v.begin(), v.end());
    cout << "next permutation of aab: ";
    printvec(v);
}

void slice_vector() {
    vector<int> v = {1, 2, 3, 4, 5};

    // slice the vector from index 1 to 3
    vector<int> v2(v.begin() + 1, v.begin() + 3);
    cout << "slice of vector [1,2,3,4,5] from index 1 to 3 (equivalent to "
            "v[1:3]): ";
    printvec(v2);
}

int main() {
    cout << "===== sort =====\n";
    stl_sort();
    cout << "==== acccumulate ====\n";
    stl_accumulate();
    cout << "==== binary search ====\n";
    stl_binary_search();
    cout << "==== erase element ====\n";
    erase_element();
    cout << "==== next permutation ====\n";
    next_permutation();
    cout << "==== slice vector ====\n";
    slice_vector();

    return 0;
}