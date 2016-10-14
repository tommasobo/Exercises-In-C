+#include <stdio.h>
#include <stdlib.h>

int main()
{
    int matrix[3][3], i, j, k, h, conta;


    // Inizializzo la matrice
    for (i=0; i < 3; i++)
        for (j=0; j < 3; j++) {
            printf("Inserisci dato coordinate (%d;%d): ",i,j);
            scanf("%d", &matrix[i][j]);
        }

    conta = 0;
    for (i=0; i < 3; i++) {
        for (j=0; j < 3; j++) {
            if (matrix[i][j] == 0) {
                for (k = i-1; k < i+2; k++)
                    for (h = j-1; h < j+2; h++)
                        if (matrix[k][h] == 1)
                            conta++;

            }
        }
    }


    if (conta == 8)
        printf("Bravo");


}
