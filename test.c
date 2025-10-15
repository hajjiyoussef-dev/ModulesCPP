


#include <stdio.h>

void foo(int *p)
{
    *p = 88;
    // printf("%p\n", &p);
    // printf("%d \n", *p);
    // printf("%p", p);
}

int main(void){


   int x = 9;
   int *p = &x;

   foo(p);
   printf("%d \n", x);

    return (0);
}