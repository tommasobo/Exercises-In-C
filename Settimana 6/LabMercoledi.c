#include <stdio.h>
#include <stdlib.h>
#define N 10

int main ()
{
    char stringa[N+1],c;
    int n,i;

    printf("Inserire una stringa di %d caratteri: ", N);
    for (i = 0; i < N+1 && (c = getchar()) != '\n'; i++)
        stringa[i] = c;
    n=i>N?N:i;
    stringa[n] = '\0';
    if (c == '\n')
        printf("Stringa letta (%d caratteri): %s\n",n,stringa);
    else {
        printf("Stringa piu lunga di %d caratteri \n",N);
        while ((c = getchar()) != '\n');
    }

    return 0;
}
