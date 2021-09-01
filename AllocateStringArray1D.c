#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int allocStringArray1D(char ***array, unsigned int height, unsigned int stringLength) {
    if (array == NULL)
        return 1;

    *array = calloc(height, sizeof(char *));
    if (*array == NULL)
        return 1;

    for (unsigned int i = 0; i < height; i++) {
        *(*array + i) = calloc(stringLength, sizeof(char));
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


void displayStringArray1D(char **array, unsigned int height) {
    if (array == NULL || height < 1)
        return;
    for (unsigned int i = 0; i < height; i++) {
        printf("%s ", *(array + i));
    }
    printf("\n");
}

void destroyStringArray1D(char ***array, unsigned int height) {
    if (array == NULL || *array == NULL || height < 1)
        return;
    for (unsigned int i = 0; i < height; i++) {
        free(*(*array + i));
    }
    free(*array);
}


int main() {
    unsigned int arrayLen = 10;
    unsigned int stringLength = 15;

    //------------------------------------------------------

    char **array1;
    if (allocStringArray1D(&array1, arrayLen, stringLength) != 0)
        return puts("Failed to allocate memory"), -1;

    //set value
    for (unsigned int i = 0; i < arrayLen; i++) {
        strcpy(array1[i], "test1");
    }

    displayStringArray1D(array1, arrayLen, stringLength);
    destroyStringArray1D(&array1, arrayLen);
    printf("\n\n");

    //------------------------------------------------------


    char **array2 = malloc(arrayLen * sizeof(char *));
    //  or -> array2 = malloc(arrayHeight * sizeof(char *));
    if (array2 == NULL)
        return puts("Failed to allocate memory"), -1;
    for (unsigned int i = 0; i < arrayLen; i++) {
        *(array2 + i) = calloc(stringLength, sizeof(char));
        if (*(array2 + i) == NULL) {
            for (unsigned int j = 0; j < i; j++) {
                free((*(array2 + j)));
            }
            free(array2);
            return 1;
        }
    }
    //set value
    for (unsigned int i = 0; i < arrayLen; i++) {
        strcpy(array2[i], "test2");
    }
    //display array
    for (unsigned int i = 0; i < arrayLen; i++) {
            printf("%s ", *(array2 + i));
    }
    //destroy array
    for (unsigned int i = 0; i < arrayLen; i++)
        free(*(array2 + i));
    free(array2);

    return 0;
}

