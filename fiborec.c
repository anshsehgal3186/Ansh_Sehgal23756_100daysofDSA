#include <stdio.h>

// Recursive function to find nth Fibonacci number
int fib(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Fibonacci(%d) = %d\n", n, fib(n));
    return 0;
}
