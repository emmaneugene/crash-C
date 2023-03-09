#include <stdio.h>
/* count characters in input; 2nd version */
int main()
{
int n;
for (n = 0; getchar() != EOF; ++n)
    ;
printf("%d\n", n);
}
