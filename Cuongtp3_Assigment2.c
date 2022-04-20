#include<stdio.h>
#include<stdlib.h>

int main()
{
    int c,k,i=4;
    for(k=1;k<=5;k++)
    {
        for(c=1;c<=i;c++)
        printf(" ");
        i--;
        for(c=1;c<=2*k-1;c++)
        printf("*");
    printf("\n");
    }
    i=1;
    for ( k=1;k<=4;k++)
    {
        for(c=1;c<=i;c++)
        printf(" ");
        i++;
        for(c=1;c <=2*(5-k)-1;c++)
        printf("*");
        printf("\n");
    }
    return 0;
} 