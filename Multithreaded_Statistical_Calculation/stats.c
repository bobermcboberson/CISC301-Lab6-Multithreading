#ifdef __STDC_NO_THREADS__
    #error "This program requires C11 <threads.h> to build"
#endif
#include <threads.h>
#include <stdio.h>

int largest_of_two_ints(int a, int b) {
    return (a > b) ? a : b;
}

int smallest_of_two_ints(int a, int b) {
    return (a < b) ? a : b;
}

float average_of_two_ints(int a, int b) {
    return (a + b)/2.0;
}

int main() {
    int num1;
    int num2;
    printf("give two ints\n");
    scanf("%d %d", &num1, &num2);
    float average = average_of_two_ints(num1, num2);
    int largets = largest_of_two_ints(num1, num2);
    int smallest = smallest_of_two_ints(num1, num2);
    printf("Average: %f\nLargest: %d\nSmallest: %d\n", average, largets, smallest);
}
