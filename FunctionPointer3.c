#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *textToUpperCase(char *text) {
    if (text == NULL)
        return NULL;

    char *modifiedText = calloc(strlen(text) + 1, sizeof(char));
    if (modifiedText == NULL)
        return NULL;

    for (unsigned int i = 0; i <= strlen(text); i++)
        *(modifiedText + i) = toupper(*(text + i));

    return modifiedText;
}

char *textToLowerCase(char *text) {
    if (text == NULL)
        return NULL;

    char *modifiedText = calloc(strlen(text) + 1, sizeof(char));
    if (modifiedText == NULL)
        return NULL;

    for (unsigned int i = 0; i <= strlen(text); i++)
        *(modifiedText + i) = tolower(*(text + i));


    return modifiedText;
}

char *modifyText(char *text, char *(*function)(char *)) {
    if (text == NULL)
        return NULL;

    return function(text);
}


int main() {

    char *text = calloc(1024, sizeof(char));
    if (text == NULL)
        return puts("Failed to allocate"), -1;
    puts("Enter text:");
    fgets(text, 1023, stdin);

    int mode;
    printf("To upper case enter 0\nTo lower case enter 1\n");
    if (scanf("%d", &mode) != 1)
        return puts("Incorrect  input"), -1;
    if (mode < 0 || mode > 1)
        return puts("Incorrect  input data"), -1;

    char *(*functionPtr)(char *, char *(*funPtr)(char *text));
    //function pointer return char* which arguments are: char* and function pointer
    functionPtr = modifyText;

    char *modifiedText;
    if (mode == 0)
        modifiedText = functionPtr(text, textToUpperCase);
    else
        modifiedText = functionPtr(text, textToLowerCase);


    if (modifiedText != NULL) {
        printf("Text before modified: %s \n", text);
        printf("Text after modified: %s \n", modifiedText);
        free(modifiedText);
    }


    free(text);
    return 0;
}
