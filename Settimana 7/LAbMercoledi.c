#include <stdio.h>
#include <stdlib.h>

#define MIN 1
#define MAX 1000

int main()
{

    int R, C;
    int **M1, **M2;
    int i, j;

    do {
        printf("Inserisci numero di righe (min %d, max %d): ", MIN, MAX);
        scanf("%d", &R);
    } while (R < MIN || R > MAX);

    do {
        printf("Inserisci numero di colonne (min %d, max %d): ", MIN, MAX);
        scanf("%d", &C);
    } while (C < MIN || C > MAX);

    if ((M1 = (int **) malloc (R*sizeof(int *))) == NULL) {
        printf("Memoria insufficiente");
        return 1;
    }

    M1[0] = (int*) malloc(R*C*sizeof(int));
    for (i=1; i < R; i++);
        M1[i] = &M1[i-1][C];




    return 0;
}
