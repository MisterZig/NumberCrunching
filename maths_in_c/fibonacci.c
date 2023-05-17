#include <stdio.h>

int fibonacci(int n) {
    int a = 0, b = 1, c;
    for (int i = 0; i < n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int fibonacci2(int n) {
    int fibo1 = 1, fibo2 = 0;
    for(int i = 1; i < n; i+=2) {
        fibo2+=fibo1;
        fibo1+=fibo2;
    }
    return n%2 ? fibo1 : fibo2;
}

int main() {
    printf("%d\n", fibonacci2(3));
}