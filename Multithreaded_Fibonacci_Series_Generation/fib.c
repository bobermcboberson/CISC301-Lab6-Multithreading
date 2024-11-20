#include <stdio.h>
#include <pthread.h>

void Fibonacci(int n) {
    int num1 = 0, num2 = 1, num3;
    printf("Fibonacci: ");
    for (int i = 1; i <= n; ++i) {     
        if (i == 1) {
            printf("%d ", num1);
            continue;
        }
        if (i == 2) {
            printf("%d ", num2);
            continue;
        }
        num3 = num1 + num2;
        num1 = num2;
        num2 = num3;
        printf("%d ", num3);
    }
    printf("\n");
}

int main() {
    int terms;
    printf("How many terms in the Fibonacci Sequence?");
    scanf("%d", &terms);
    if (terms <= 0) {
        printf("Can't have less than 0 terms\n");
        return 0;
    } else {
        Fibonacci(terms);
    }
}
