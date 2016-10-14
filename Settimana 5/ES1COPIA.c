/*
 * Enrico Salvucci
 *
 * Esercizio 5
 * Settimana 7
 *
 *
 * Consegna: Scrivere un programma C che realizzi il gioco della vita, l’automa cellulare di Conway.
 * 			 Gestire quindi la mappa di dimensione NxM che rappresenta il mondo tramite una matrice i cui valori rappresentino la presenza o meno di un organismo nel mondo.
 * 			 Partendo da una configurazione iniziale degli organismi a vostra scelta, far evolvere la popolazione nel tempo secondo le tre seguenti regole genetiche:
 * 				– un organismo sopravvive fino alla generazione successiva se ha 2 o 3 vicini
 * 				– un organismo muore, lasciando la cella vuota, se ha più di 3 o meno di 2 vicini
 * 				– ogni cella vuota con 3 vicini diventa una cella di nascita e alla generazione successiva viene occupata da un organismo.
 * 			 Si visualizzi l’evoluzione della popolazione nel tempo.
 *
 */

 #include <stdio.h>
 #include <malloc.h>
 #include <stdlib.h>
 #define X 10
 #define Y 10

 // il programma non funziona ancora del tutto

 int y_tmp, x_tmp, vicini, organismi_vivi = 0;
 int mondo[Y][X];

// controllo quanti vicini vivi ha un organismo
int controllo_vicini()
	{

		while ( mondo[Y][X] == 1 )
			{
				y_tmp = Y;
				x_tmp = X;
				for ( y_tmp = 0; y_tmp < Y + 3; y_tmp++ )
					{

						for ( x_tmp = 0; x_tmp < X + 3; x_tmp++)
							{
								if ( mondo[Y][X] == 1 )
									vicini++;
							}

					}
			}
		vicini = vicini - 1; // -1 perchè viene contata anche la cella di cui si stanno calcolando i vicini!


		return vicini;
	}

// popolo il "mondo"
int riempimento_celle()
	{
		int y_tmp, x_tmp;

		// popolo le celle del "mondo" attraverso la funzione rand();
		for ( y_tmp = Y; y_tmp > 0; y_tmp-- )
					{

						for ( x_tmp = X; x_tmp > 0; x_tmp--)
							{
								mondo[y_tmp][x_tmp] = rand() % 2;
							}

					}
		return mondo[y_tmp][x_tmp];
	}

// controllo che ci siano ancora elementi vivi nel "mondo", in modo da continuare il ciclo
int controllo_elementi_mondo()
	{
		// per ogni cella della matrice controllo quanti vicini ha un organismo
		int organismi_vivi;
		for ( y_tmp = Y; y_tmp > 0; y_tmp-- )
					{

						for ( x_tmp = X; x_tmp > 0; x_tmp--)
							{
								if ( mondo[y_tmp][x_tmp] == 1 )
								organismi_vivi++;
							}
					}
		return organismi_vivi;
	}
// stampo gli elementi del "mondo"
int stampa_mondo()
	{
		riempimento_celle();

		for (y_tmp = 0; y_tmp < Y; y_tmp++)
			{
				for (x_tmp = 0; x_tmp < X; x_tmp++)
					printf("%d ", mondo[y_tmp][x_tmp]);
				printf("\n");
			}
		return 0;
	}

int main()
	{

		// stampo il "mondo"
		stampa_mondo();
		// Controllo i vicini
		controllo_elementi_mondo();

		while ( organismi_vivi > 0 )
			{
				// ripopolo la matrice in base ai vicini di ogni organismo
				for (y_tmp = 0; y_tmp < Y; y_tmp++)
					{
						for (x_tmp = 0; x_tmp < X; x_tmp++)
						{
							controllo_vicini();
							if ( vicini == 2 || vicini == 3 )
								mondo[y_tmp][y_tmp] = 1;
							else
								if ( vicini > 3 || vicini < 2 )
									mondo[y_tmp][x_tmp] = 0;
								else
									if ( mondo[y_tmp][x_tmp] == 0 && vicini == 3 )
										mondo[y_tmp][x_tmp] = 1;
						}
					}
						printf("\n");
						stampa_mondo();
						controllo_elementi_mondo();
			}

	return 0;
	}/*
    0: cellula viva
    (spazio vuoto): cellula morta

    Decido di lasciare vuoti i bordi

*/
/*
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define N 20
#define M 50

int main ()
{

    srand(time(NULL));

    char matrice[N][M], matricetemp[N][M];
    int i, j, vicini, ciclo = 0, cicli;

    //inizializzo le due matrici come cellule morte
    for (i = 0; i < N; i++)
        for(j = 0; j < M; j++) {
            matrice[i][j] = ' ';
            matricetemp[i][j] = ' ';
        }

    //genero la prima matrice casualmente
    for (i = 1; i < N-1; i++)
        for (j = 1; j < M-1; j++) {
            matrice[i][j] = rand() % 2; //genero o 0 o 1
            if (matrice[i][j] == 1)
                matrice[i][j] =' ';
            else
                matrice[i][j]='0';
        }

    //stampo la matrice
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++)
            printf("%c", matrice[i][j]);
        printf("\n");
    }


    //se si vuole fare inserire all'utente da tastiera il numero di generazioni da vedere
//    printf("Inserisci quante generazioni vuoi vedere: ");
//    scanf("%d", &cicli);

    system("clear");

//    while (ciclo<cicli) {

    //altrimenti pongo una condizione sempre vera per fare continuare il ciclo all'infinito
    while (0 < 1) {
    //controllo i vicini
        for (i = 1; i < N-1; i++)
            for (j = 1; j < M-1; j++) {
                vicini = 0;
                if (matrice[i-1][j-1] == '0')
                    vicini++;
                if (matrice[i-1][j] == '0')
                    vicini++;
                if (matrice[i-1][j+1] == '0')
                    vicini++;
                if (matrice[i][j-1] == '0')
                    vicini++;
                if (matrice[i][j+1] == '0')
                    vicini++;
                if (matrice[i+1][j-1] == '0')
                    vicini++;
                if (matrice[i+1][j] == '0')
                    vicini++;
                if (matrice[i+1][j+1] == '0')
                    vicini++;

                //controllo le tre condizioni di sopravvivenza o estinzione imposte alla base del gioco della vita
                if (vicini == 2 || vicini == 3 && matrice[i][j] == '0')
                    matricetemp[i][j] = '0';
                else if (vicini < 2 || vicini > 3 && matrice[i][j] == '0')
                    matricetemp[i][j] = ' ';
                else if (vicini == 3 && matrice[i][j] == ' ')
					matricetemp[i][j] = '0';
                //else
					//matricetemp[i][j] = matrice[i][j];
            }

        //riassegno i valori delle matrici
        for(i = 0; i < N; i++)
            for(j = 0; j < M; j++){
                matrice[i][j] = matricetemp[i][j];
                matricetemp[i][j] = ' ';
            }

        //stampo la matrice
        for (i = 0; i < N; i++){
            for (j = 0; j < M; j++)
                printf("%c", matrice[i][j]);
            printf("\n");
        }

    // system("pause");

    //ripulisco la schermata
    sleep(1);
    system("cls");
    //ciclo++;

    }

    return 0;

}
*/
