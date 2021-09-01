#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int allocStringArray2D(char ****array, unsigned int height, unsigned int width, unsigned int stringLength) {
    if (array == NULL)
        return 1;

    *array = calloc(height, sizeof(char *));
    if (*array == NULL)
        return 1;

    for (unsigned int i = 0; i < height; i++) {
        *(*array + i) = calloc(width, sizeof(char *));
        if (*(*array + i) == NULL) {
            for (unsigned int j = 0; j < i; j++) {
                free((*(*array + j)));
            }
            free(*array);
            return 1;
        }
    }

    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            *(*(*array + i) + j) = calloc(stringLength, sizeof(char));
            if (*(*(*array + i) + j) == NULL) {
                for (unsigned int k = 0; k < i; k++) {
                    for (unsigned int l = 0; l < width; l++) {
                        free(*(*(*array + k) + l));
                    }
                }
                for (unsigned int l = 0; l < j; l++) {
                    free(*(*(*array + i) + l));
                }
                for (unsigned int l = 0; l < height; l++) {
                    free(*(*array + l));
                }
                free(*array);
                return 1;
            }
        }
    }
    return 0;
}


void displayStringArray2D(char ***array, unsigned int height, unsigned int width) {
    if (array == NULL || *array == NULL || **array == NULL || height < 1 || width < 1)
        return;
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            printf("%s ", *(*(array + i) + j));
        }
        printf("\n");
    }
    printf("\n");
}

void destroyStringArray2D(char ****array, unsigned int height, unsigned int width) {
    if (array == NULL || *array == NULL || **array == NULL  || height < 1)
        return;
    for (unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            free(*(*(*array + i) + j));
        }
        free(*(*array + i));
    }
    free(*array);
}


int main() {
    unsigned int arrayHeight = 10;
    unsigned int arrayWidth = 25;
    unsigned int stringLength = 100;

    //------------------------------------------------------

    char ***array1;
    if (allocStringArray2D(&array1, arrayHeight, arrayWidth, stringLength) != 0)
        return puts("Failed to allocate memory"), 1;
    //set values
    for (unsigned int i = 0; i < arrayHeight; i++) {
        for (unsigned int j = 0; j < arrayWidth; j++) {
            strcpy(*(*(array1 + i) + j), "test");
        }
    }
    displayStringArray2D(array1, arrayHeight, arrayWidth);
    destroyStringArray2D(&array1, arrayHeight, arrayWidth);

    return 0;
}

