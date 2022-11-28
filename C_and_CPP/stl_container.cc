#include <bits/stdc++.h>
using namespace std;

void demo_heap() {
    // heap = priority queue
    // lookup: O(1), insert: O(logn), delete: O(logn)
    priority_queue<int> max_heap;
    max_heap.push(10);
    max_heap.push(20);
    max_heap.push(5);
    max_heap.push(1);

    cout << "max heap: ";
    while (!max_heap.empty()) {
        // similar to stack operations
        cout << max_heap.top() << " ";
        max_heap.pop();
    }
    cout << endl;  // 20 10 5 1

    priority_queue<int, vector<int>, greater<int> > min_heap;
    min_heap.push(10);
    min_heap.push(20);
    min_heap.push(5);
    min_heap.push(1);
    cout << "min heap: ";
    while (!min_heap.empty()) {
        // similar to stack operations
        cout << min_heap.top() << " ";
        min_heap.pop();
    }
    cout << endl;  // 1 5 10 20
}

int main() {
    cout << "==== Demo of max-heap (priority queue) ====" << endl;
    demo_heap();

    return 0;
}