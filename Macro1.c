#include <stdio.h>

#define SUM_NUMBERS(TYPE) \
TYPE sum_##TYPE##_Numbers(TYPE number1, TYPE number2) \
{ \
    return number1+number2; \
}


#define DISPLAY(TYPE, FORMAT) \
void display_##TYPE (TYPE value) \
{ \
    printf(#FORMAT,value);  \
    printf("\n");  \
}


SUM_NUMBERS(int)

SUM_NUMBERS(float)

DISPLAY(int, %d)

typedef char *string;

DISPLAY(string, %s)

int main() {

    printf("%d\n", sum_int_Numbers(12, 13));
    printf("%f\n", sum_float_Numbers(2.12, 4.83));

    display_int(12);
    display_string("Alice has a cat");

    return 0;
}
