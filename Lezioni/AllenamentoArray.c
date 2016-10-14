#include <stdio.h>

int main()
{
    /*int vettore[10] = {44, 54};

    printf("Esempio 1: %d\n", *vettore);
    printf("Esempio 2: %d\n", vettore[0]);*/

    int *iPtr;
int vettore[15]={10,20,30,40,50};
printf("indirizzo di vettore: %X\n", vettore);
iPtr = vettore;
printf("indirizzo di vettore : %X\n",iPtr);
printf("primo elemento di vettore : %d\n",* vettore);
printf("secondo elemento di vettore : %d\n",*(vettore +1));
++iPtr;
printf("secondo elemento di vettore : %d\n",*iPtr);


    return 0;
}
