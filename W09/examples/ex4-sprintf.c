#include <stdio.h>

int main(void) {
    /* The sprintf() function stores output to a "buffer" - which is basically an array declared previously
    At the same time, it returns the number of characters stored
    It takes in 3 arguments:
    1 - Buffer to write to
    2 - Format specifier for content to write (e.g. "%s" , "%d", "%c", ...)
    3 - What we want to write 
    Format: int sprintf(char *str, const char *format, ...)
    */

    char line[50] = {0};
    // Work with a pointer
    char *ptr = line;

    // This enables us to store arrays of various datatypes into a char*

    char* name = "Emmanuel";
    int num = 50;

    ptr += sprintf(ptr, "My name is %s, %d", name);
    ptr += sprintf(ptr, ", my age is %d", num);
    ptr += sprintf(ptr, ", nice to meet you!");

    printf("%s\n", line);
    // sprintf is an excellent function to help you concatenate strings (like in python)
}