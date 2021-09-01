#include <stdio.h>
#include <math.h>

#define DISPLAY(...) printf(__VA_ARGS__)

#define MAX(number1, number2) (number1) > (number2) ? (number1) : (number2)

#define MEDIAN(x, y, z) \
(((x)<(y) && (x)>(z)) || ((x)>(y) && (x)<(z))) ? \
(x) : \
(((y)<(x) && (y)>(z)) || ((y)>(x) && (y)<(z))) ? \
(y) : \
(z)

int main() {
    //.......................
    DISPLAY("%s %d\n", "Compiled is line number: ", __LINE__);
    //.......................
    int number = 3;
    char *text = "Three";
    DISPLAY("%s: %d\n", text, number);
    //........................
    printf("MAX: %d\n", MAX(5, 120));
    DISPLAY("MAX %d\n", MAX(5, 120));
    //........................
    printf("MAX: %0.2lf\n", MAX(sqrt(2), 1.33333));
    DISPLAY("MAX %0.4lf\n", MAX(sqrt(2), 1.33333));
    //........................
    printf("Median of three numbers: %d",MEDIAN(13*5,18*2,6));
    return 0;
}
