#include <stdio.h>
#include <stdlib.h>
#define N 6
#define R 1

int main()
{
    int M[N][N];
    int i, j, a, b, x;

    x = 0;

    srand(10);
    for (i=0; i < N; i++)
        for (j=0; j < N; j++)
            M[i][j] = rand() % 2;

    printf("Matrice iniziale: \n");
    for (i=0; i < N; i++) {
        for (j=0; j < N; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    printf("\nMatrice comme con background nullo:\n");
    for (i=0; i < N; i++) {
        for (j=0; j < N; j++) {
            x = 0;
            for (a = -R; a <= R; a++)
                for (b = -R; b <= R; b++)
                    if (!(i+a < 0 || i+a >= N || j+b < 0 || j+b >= N))
                    x += M[i+a][j+b];
                printf("%d ", x);
        }
        printf("\n");
    }

    return 0;

}
