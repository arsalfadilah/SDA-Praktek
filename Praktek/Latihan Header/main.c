#include <stdio.h>
#include <conio.h>
#include "foo.h"  /* Include the header here, to obtain the function declaration */

int main(void)
{
    int y = foo(3);  /* Use the function here */
    printf("%d\n", y);

    getch();

    return 0;
}
