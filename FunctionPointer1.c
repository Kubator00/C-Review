#include <stdio.h>


double add_number(double number1, double number2) {
    return number1 + number2;
}

double subtract_number(double number1, double number2) {
    return number1 - number2;
}

double multiply_number(double number1, double number2) {
    return number1 * number2;
}

double divde_number(double number1, double number2) {
    if (number2 == 0)
        return printf("Error"), 0;
    return number1 / number2;
}


int main() {

    double (*functionsPtr[4])(double, double) = {
            add_number,
            subtract_number,
            multiply_number,
            divde_number
    };
    // 5 + 3
    printf("ADD: %lf\n", functionsPtr[0](5, 3));

    // 5 - 3
    printf("SUBTRACT: %lf\n", functionsPtr[1](5, 3));

    // 5 * 3
    printf("MULTIPLY: %lf\n", functionsPtr[2](5, 3));

    // 5 / 3
    printf("DIVIDE: %lf\n", functionsPtr[3](5, 3));

    return 0;
}
