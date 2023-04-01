#include <iostream>
#include <stdlib.h>
using namespace std;

void test() {
    int i;
    i = 1, 2, 3;
    printf("i  = %d\n", i);
}

int modify_value_in_if() {
    int k = 6;
    if (++k > 8 && ++k < 10 || k++ >= 7) {
        // decompose the expression:
        // 1. k = 7, 7 > 8, false
        // 2. k = 7, 7 < 10, true
        // 3. k = 7, 7 >= 7, true
        // 4. true || true, true
        return k;
    }
    return 0;
}

int main() {
    test();
    // cout << modify_value_in_if() << endl;
    return 0;
}