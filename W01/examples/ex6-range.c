/* 
1. Understand that datatypes have different memory sizes and hence value ranges
2. Appreciate the correct use of such datatypes when handling devices with memory constraints

char

short int, int, long int, long long int

float, double, long double
 */
#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void){
    printf("size of char       : %lu byte\n", sizeof(char));
    printf("size of short int  : %lu bytes\n", sizeof(short));
    printf("size of int        : %lu bytes\n", sizeof(int));
    printf("size of long int   : %lu bytes\n", sizeof(long));
    printf("size of float      : %lu bytes\n", sizeof(float));
    printf("size of double     : %lu bytes\n", sizeof(double));
    printf("size of long double: %lu bytes\n\n", sizeof(long double));

    printf("CHAR        :   8 bits\n");
    printf("CHAR_MAX    :   %d\n", CHAR_MAX);
    printf("CHAR_MIN    :   %d\n\n", CHAR_MIN);

    printf("SHRT        :   16 bits\n");
    printf("SHRT_MAX    :   %d\n", SHRT_MAX);
    printf("SHRT_MIN    :   %d\n\n", SHRT_MIN);
    printf("USHRT_MAX   :   %d\n", USHRT_MAX);

    printf("INT         :   32 bits\n");
    printf("INT_MAX     :   %d\n", INT_MAX);
    printf("INT_MIN     :   %d\n\n", INT_MIN);
    printf("UINT_MAX    :   %u\n", UINT_MAX);

    printf("LONG        :   64 bits\n");
    printf("LONG_MAX    :   %ld\n", LONG_MAX);
    printf("LONG_MIN    :   %ld\n\n", LONG_MIN);
    printf("ULONG_MAX   :   %lu\n", ULONG_MAX);

}