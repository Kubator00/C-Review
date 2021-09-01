#include <stdio.h>
#include <stdlib.h>

#define arrayLen 10

int *create_array1d(int len) {
    if (len < 1)
        return printf("Error"), NULL;

    int *array = calloc(len, sizeof(int));
    if (array == NULL)
        return NULL;

    return array;
}

int main() {

    int *array;
    int *(*functionPtr)(int) = create_array1d;

    array = (*functionPtr)(arrayLen); //alloc 1d array, size = arrayLen

    if (array == NULL)
        return puts("Failed to allocate memory"), -1;

    for (int i = 0; i < arrayLen; i++)
        *(array + i) = i;

    for (int i = 0; i < arrayLen; i++)
        printf("%d ", *(array + i));

    free(array);

}
