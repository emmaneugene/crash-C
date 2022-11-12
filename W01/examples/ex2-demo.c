/*
1. Compile and execute a program
2. Use the -o switch when compiling to specify the name of the output file

compilation is the process of converting source code into machine readable binary code

when you use code runner to run a piece of code (for example demo.c), it does 3 things:

cd "mnt/c/workspace/CS101/week1" -> change directory to the directory that the file is located in

&& clang -Wall demo.c -o demo -> asks clang compiler to compile the source code and specifies the name of the output. -Wall gets the compiler to output all 
warnings or errors encountered

&& "mnt/c/workspace/CS101/week1/"demo -> runs the compiled binary
*/
#include <stdio.h>

int main(void) {
    printf("Hello, world!\n");
}