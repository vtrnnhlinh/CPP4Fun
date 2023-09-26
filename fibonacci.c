#include <stdio.h>

int main() {
    int fib0 = 0;
    int fib1 = 1;
    printf("%d\n", fib0);
    printf("%d\n", fib1);
    for (int i = 0; i < 4; i++) {
        int fib = fib0 + fib1;
        printf("%d\n", fib);
        fib0 = fib1;
        fib1 = fib;
    }
    return 0;
}