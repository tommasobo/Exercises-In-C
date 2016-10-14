#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 5
#define COL 10

int main()
{
    int matrix[ROW][COL],conta[3],i,j,conta0 = {0}, conta1, conta2;

    srand((unsigned) time(NULL));

    for (i=0; i < ROW; i++)
        for (j=0; j < COL; j++)
            matrix[i][j] = rand() % 3;

    for (i=0; i < ROW; i++) {
        for (j=0; j < COL; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    conta0 = conta1 = conta2 = 0;
    for (i=0; i < ROW; i++)
        for (j=0; j < COL; j++)
            /*switch(matrix[i][j]) {
                case 0:
                    conta0++;
                    break;
                case 1:
                    conta1++;
                    break;
                case 2:
                    conta2++;
                    break;
            }


            if (matrix[i][j] == 0)
                conta0++;
            else if (matrix[i][j] == 1)
                conta1++;
            else if (matrix[i][j] == 2)
                conta2++;*/
                conta[matrix[i][j]]++;


    return 0;
}
