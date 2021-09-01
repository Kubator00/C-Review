#include <stdio.h>
#include <stdlib.h>


int allocArray2D(int ***array, unsigned int height, unsigned int width) {
    if (array == NULL)
        return 1;

    *array = calloc(height, sizeof(int *));
    if (*array == NULL)
        return 1;

    for (unsigned int i = 0; i < height; i++) {
        *(*array + i) = calloc(width, sizeof(int));
        if (*(*array + i) == NULL) {
            for (unsigned int j = 0; j < i; j++) {
                free((*(*array + j)));
            }
            free(*array);
            return 1;
        }
    }
    return 0;
}

void displayArray2D(int **array, unsigned int height, unsigned int width) {
    if (array == NULL)
        return;

    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            printf("%d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}

void destroyArray2D(int ***array, unsigned int height) {
    if (array == NULL || *array == NULL )
        return;
    for (unsigned int i = 0; i < height; i++) {
        free(*(*array + i));
    }
    free(*array);
}


int main() {
    unsigned int arrayHeight = 10;
    unsigned int arrayWidth = 22;

    //------------------------------------------------------

    int **array1;
    if (allocArray2D(&array1, arrayHeight, arrayWidth) != 0)
        return puts("Failed to allocate memory"), -1;

    //set value
    for (unsigned int i = 0; i < arrayHeight; i++) {
        for (unsigned int j = 0; j < arrayWidth; j++)
            array1[i][j] = i + 1;
    }

    displayArray2D(array1, arrayHeight, arrayWidth);
    destroyArray2D(&array1, arrayHeight);
    printf("\n\n");

    //------------------------------------------------------

    int **array2 = malloc(arrayHeight * sizeof(int *));
    //  or -> array2 = malloc(arrayHeight * sizeof(int *));
    if (array2 == NULL)
        return puts("Failed to allocate memory"), -1;
    for (unsigned int i = 0; i < arrayHeight; i++) {
        *(array2 + i) = calloc(arrayWidth, sizeof(int));
        if (*(array2 + i) == NULL) {
            for (unsigned int j = 0; j < i; j++) {
                free((*(array2 + j)));
            }
            free(array2);
            return 1;
        }
    }
    //set value
    for (unsigned int i = 0; i < arrayHeight; i++) {
        for (unsigned int j = 0; j < arrayWidth; j++) {
            *(*(array2 + i) + j) = i * 10 + j;
        }
    }
    //display array
    for (unsigned int i = 0; i < arrayHeight; i++) {
        for (unsigned int j = 0; j < arrayWidth; j++) {
            printf("%d ", *(*(array2 + i) + j));
        }
        printf("\n");
    }
    //destroy array
    for (unsigned int i = 0; i < arrayHeight; i++)
        free(*(array2 + i));
    free(array2);

    return 0;
}

