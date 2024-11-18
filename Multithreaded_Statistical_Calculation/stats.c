#ifdef __STDC_NO_THREADS__
    #error "This program requires C11 <threads.h> to build"
#endif
#include <threads.h>
#include <stdio.h>

typedef struct {
    int a;
    int b;
    int result;
    float average;
} thread_data;

int largest_of_two_ints(void *args) {
    //return (a > b) ? a : b;
    thread_data *data = (thread_data *)args;
    data->result = (data->a > data -> b) ? data->a : data ->b;
    return 0;
}

int smallest_of_two_ints(void *args) {
    //return (a < b) ? a : b;
    thread_data *data = (thread_data *)args;
    data->result = (data->a < data -> b) ? data->a : data ->b;
    return 0;
}

int average_of_two_ints(void *args) {
    //return (a + b)/2.0;
    thread_data *data = (thread_data *)args;
    data->average = (data->a + data->b) / 2.0;
    return 0;
}

int main() {
    int num1, num2;
    printf("give two ints\n");
    scanf("%d %d", &num1, &num2);
    
    //float average = average_of_two_ints(num1, num2);
    //int largets = largest_of_two_ints(num1, num2);
    //int smallest = smallest_of_two_ints(num1, num2);
    
    thread_data average_data = {num1, num2, 0, 0.0};
    thread_data largest_data = {num1, num2, 0, 0.0};
    thread_data smallest_data = {num1, num2, 0, 0.0};

    thrd_t thread1, thread2, thread3;

    thrd_create(&thread1, average_of_two_ints, &average_data);
    thrd_create(&thread2, largest_of_two_ints, &largest_data);
    thrd_create(&thread3, smallest_of_two_ints, &smallest_data);

    thrd_join(thread1, NULL);
    thrd_join(thread2, NULL);
    thrd_join(thread3, NULL);

    printf("Average: %f\nLargest: %d\nSmallest: %d\n", average_data.average, largest_data.result, smallest_data.result);
}
