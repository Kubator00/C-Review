#include <stdio.h>
#include <stdlib.h>

int allocArray1D(int **array, unsigned int arrayLen) {
    if (array == NULL)
        return 1;

    *array = calloc(arrayLen, sizeof(int));
    if (*array == NULL)
        return 1;

    return 0;
}

void displayArray1D(int *array, unsigned int arrayLen) {
    if (array == NULL)
        return;
    for (unsigned int i = 0; i < arrayLen; i++)
        printf("%d ", *(array + i));
}

void destroyArray1D(int **array) {
    if (array == NULL)
        return;

    free(*array);
}


int main() {
    unsigned int arrayLen = 15;

    //------------------------------------------------------
    int *array1;
    if (allocArray1D(&array1, arrayLen) != 0)
        return puts("Failed to allocate memory"), 1;
    //set values
    for (unsigned int i = 0; i < arrayLen; i++)
        array1[i] = i + 1;

    displayArray1D(array1, arrayLen);
    destroyArray1D(&array1);
    printf("\n\n");

    //------------------------------------------------------

    int *array2 = malloc(arrayLen * sizeof(int));
//  or -> array2 = malloc(arrayLen * sizeof(int));
    if (array2 == NULL)
        return puts("Failed to allocate memory"), 1;
    //set values
    for (unsigned int i = 0; i < arrayLen; i++)
        *(array2 + i) = (i + 1) * 10;
    //display array
    for (unsigned int i = 0; i < arrayLen; i++)
        printf("%d ", *(array2 + i));
    free(array2);

    return 0;
}

