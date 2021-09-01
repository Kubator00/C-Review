#include <stdio.h>
#include <stdarg.h>

#define arrayLen 5

int sumIntArrays1D(unsigned n, ...) {
    va_list args;
    va_start(args, n);
    int sum = 0;
    for (unsigned i = 0; i < n; i++) {
        int *array = va_arg(args,int*);
        for (int j = 0; j < arrayLen; j++) {
            sum += array[j];
        }
    }
    va_end(args);
    return sum;
}


int main() {

    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5] = {10, 20, 30, 40, 50};
    int array3[5] = {100, 200, 300, 400, 500};

    printf("Sum: %d", sumIntArrays1D(3, array1, array2, array3));

    return 0;
}
