#include <iostream>
// q1: seconds per year using define
#define SECONDS_PER_YEAR (60 * 60 * 24 * 365UL)
// q2: MIN macro
#define MIN(a, b) ((a) < (b) ? (a) : (b))
using namespace std;

int static_func() {
    static int count = 0;
    count++;
    return count;
}

int non_static() {
    int count = 0;
    count++;
    return count;
}

void static_vs_non_static() {
    // q6: static variable
    // static variable is initialized only once, and the value is kept
    printf("%d ", static_func());  // output 1
    printf("%d ", static_func());  // output 2
    //================================
    printf("%d ", non_static());  // output 1
    printf("%d ", non_static());  // output 1
}

void spiral_rule() {
    int b;
    // q7: different meaning of const
    const int* ptr;              // ptr is a pointer to a const int
    int* const ptr2 = &b;        // ptr2 is a const pointer to an int
    const int* const ptr3 = &b;  // ptr3 is a const pointer to a const int
    // string(const** f(int, void (*const p)(int)))(char[]);
    //   f is a function with arguments as int and p a function with the
    //   argument as int, returning a constant pointer to nothing (void)
    //   returning a pointer to a pointer to a constant function with the
    //   character array as an argument returning a string.
}

#define BIT3 (0x1 << 3)
void set_unset_bit3() {
    int temp = 133;  // 10000101
    // q9: set bit 3
    temp |= BIT3;
    cout << temp << endl;  // output 141 (10001101)
    temp &= ~BIT3;
    cout << temp << endl;  // output 133 (10000101)
}

void accessing_fixed_memloc() {
    // q10: accessing fixed memory location, set integer variable at 0x67a9
    // point to 0xaa55
    int* p;
    p = (int*)0x67a9;   // typecast to int*, set p to 0x67a9
    cout << p << endl;  // output 0x67a9
    p = (int*)0xaa55;   // set the value at 0x67a9 to 0xaa55
    cout << p << endl;  // output 0xaa55
}

/*
__interrupt void compute_area() {
    // q11: interrupt function
}*/

void foo(void) {
    // q12:
    unsigned int a = 6;
    int b = -20;
    (a + b > 6) ? puts("> 6") : puts("<= 6");
    // output > 6
    // int is promoted to unsigned int, so the result is 4294967282
    cout << a + b << endl;

    // q13:
    unsigned int zero = 0;
    unsigned int comp_zero = 0xFFFF;  // incorrect if int is not 16 bits
    unsigned int comp_zero2 = ~zero;  // correct method
    cout << comp_zero << endl;        // output 0xFFFF
    cout << comp_zero2 << endl;       // output 0xFFFFFFFF
}

char* ptr;

if ((ptr = (char*)malloc(0)) == NULL) {
    puts(“Got a null pointer”);

}

else {
    puts(“Got a valid pointer”);
}

int main() {
    foo();
    return 0;
}
