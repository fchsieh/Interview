#include <bits/stdc++.h>
using namespace std;

void printvec(const vector<int>& v) {
    for (auto i : v) cout << i << " ";
    cout << endl;
}

void stl_sort() {
    vector<int> v = {1, 3, 2, 5, 4};
    sort(v.begin(), v.end());
    cout << "sort in ascending order: ";
    printvec(v);

    sort(v.begin(), v.end(), greater<int>());
    cout << "sort in descending order: ";
    printvec(v);
}

void stl_accumulate() {
    vector<int> v = {1, 2, 3, 4, 5};
    int sum = accumulate(v.begin(), v.end(), 0);  // 0 is the initial value
    cout << "sum of all elements: " << sum << endl;
}

int main() {
    stl_sort();
    stl_accumulate();

    return 0;
}