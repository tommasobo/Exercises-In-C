#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#define ROW 5
#define COL 5
#define R 1

int main()
{
    int matrice[ROW][COL], tempMatrix[ROW][COL];
    int stato, i, j, x, a, b;

    // Uso la funzione srand usando come argomento l'ora per generare numeri sempre casuali
    srand((unsigned) time(NULL));

    // Inizializzo la matrice casualmente
    for (i=0; i < ROW; i++)
        for (j=0; j < COL; j++) {
            matrice[i][j] = rand() % 2;
        }

    // Stampo la matrice iniziale
    for (i=0; i < ROW; i++) {
        for (j=0; j < COL; j++) {
            if (matrice[i][j] == 1)
                matrice[i][j] = '@';
            else
                matrice[i][j] = ' ';
            printf("%c ", matrice[i][j]);
            if (matrice[i][j] == '@')
                matrice[i][j] = 1;
            else
                matrice[i][j] = 0;
        }
        printf("\n");
    }
    //system("cls");
    // Condizioni di vita
    while (5) {

    for(i=0; i<ROW; i++) {
		for(j=0; j<COL; j++) {
			if (matrice[i][j] == '@')
                x = 0;
            else
                x = 0;
			for(a=-R; a<=R; a++)
				for(b=-R; b<=R; b++) {

						/*ia k un intero tale che -1<=k<=N. L'espressione (k+N)%N restituisce:
						1) k   se 0<=k<N
						2) 0   se k=N
						3) N-1 se k=-1*/

                    //if (matrice[i][j] == ' ')
                      //  x+= 32;
					x+=((matrice[(i+a+ROW)%ROW][(j+b+COL)%COL]));
					/*if (x == (2*64) || x == (3*64) && matrice[i][j] == 64)
                        tempMatrix[i][j] = 64;
                    else if (x < (2*64) || x > (3*64) && matrice[i][j] == 64)
                        tempMatrix[i][j] = 32;
                    else if (x == (3*64) && matrice[i][j] == 32)
                        tempMatrix[i][j] == 64;
                    else
                        tempMatrix[i][j] = matrice[i][j];*/
				}

			tempMatrix[i][j]=x;
		}
	}

	//printf("\nMatrice delle somme, assumendo matrice toroidale\n");
	for(i=0; i<ROW; i++) {
		for(j=0; j<COL; j++)
			matrice[i][j] = tempMatrix[i][j];
	}


        for (i=0; i < ROW; i++) {
            for (j=0; j < COL; j++) {
               /* if (matrice[i][j] == 1)
                    matrice[i][j] = 64;
                else
                    matrice[i][j] = 32;*/
                printf("%d ", matrice[i][j]);
                /*if (matrice[i][j] == 64)
                    matrice[i][j] = 1;
                else
                    matrice[i][j] = 0;*/
            }
            printf("\n");
        }

    sleep(50);
        system("cls");
	}


    return 0;
}
