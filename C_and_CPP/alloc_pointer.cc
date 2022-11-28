#include <bits/stdc++.h>
using namespace std;

int **cpp_style_alloc(int n) {
    int **a = new int *[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }
    return a;
}

int **c_style_alloc(int n) {
    int **a = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        a[i] = (int *)malloc(n * sizeof(int));
    }
    return a;
}

void cpp_style_free(int **a, int n) {
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;
}

void c_style_free(int **a, int n) {
    for (int i = 0; i < n; i++) {
        free(a[i]);
    }
    free(a);
}

int main() {
    // allocates a 2D array of size 10x10
    int **cpp = cpp_style_alloc(10);
    int **c = c_style_alloc(10);

    cpp_style_free(cpp, 10);
    c_style_free(c, 10);

    return 0;
}
