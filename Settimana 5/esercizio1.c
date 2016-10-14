/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Il programma è compatibile solo con Windows in quanto vengono usate le chiamate a system e la funzione kbhit
    * In alcune architetture la funzione sleep() potrebbe richiedere millisecondi come argomento e non secondi
    * Il simbolo '#' indica un organismo vivo
    * La matrice è stata considerata come toroidale.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>
#define ROW 20 // Definisco il numero di righe della matrix
#define COL 60 // Definisco il numero di colonne della matrix
#define R 1 // Definisco una costante R che verrà utilizzata per il calcolo della cella

int main()
{
    int matrix[ROW][COL], tempMatrix[ROW][COL];
    int conta, i, j, x, a, b, number, k;

    // Uso la funzione srand usando come argomento il tempo per generare numeri sempre pseudo-casuali
    srand((unsigned) time(NULL));

    // Richiedo all'utente quante generazioni desidera visualizzare e controllo che il numero inserito sia positivo
    printf("Quante generazioni si desidera visualizzare?\nPremere 1 per avere un ciclo infinito: ");
    scanf("%d", &number);
    while (number <= 0) {
        printf("Errore, devi inserire un numero intero positivo: ");
        scanf("%d", &number);
    }

    // Inizializzo la matrice casualmente con 0 o 1
    for (i=0; i < ROW; i++)
        for (j=0; j < COL; j++) {
            matrix[i][j] = rand() % 2;
            if (matrix[i][j] == 1)
                matrix[i][j] = '#';
            else
                matrix[i][j] = ' ';
        }

    // Stampo la matrice iniziale
    for (i=0; i < ROW; i++) {
        for (j=0; j < COL; j++) {
            printf("%c", matrix[i][j]); // Per la stampa uso un casting a char per visualizzare il carattere corrispondente
            // Trasformo nuovamente il carattere # in 1 e lo spazio in 0 per eseguire le operazioni di controllo
            if (matrix[i][j] == '#')
                matrix[i][j] = 1;
            else
                matrix[i][j] = 0;
        }
        printf("\n");
    }

    sleep(1); // Pauso il sistema per un secondo (in alcune architetture l'argomento potrebbere essere in millisecondi)
    system("cls"); // Pulisco lo schermo - Compatibile solo con Windows

    // Il ciclo while si ripete per il numero generazioni scelte dall'utente o infinitamente se l'utente l'ha scelto.
    k=1;
    while (k <= number) {
        for(i=0; i < ROW; i++) {
            for(j=0; j < COL; j++) {
                // Se la casella attuale è viva devo togliere 1 dalla somma delle otto caselle adiacenti in quanto viene contata anche se stessa
                if (matrix[i][j] == 1)
                    x = -1;
                else
                    x = 0;
                for(a=-R; a <= R; a++)
                    for(b=-R; b <= R; b++) {

                            /*
                            Sia k un intero tale che -1<=k<=N. L'espressione (k+N)%N restituisce:
                            1) k   se 0<=k<N
                            2) 0   se k=N
                            3) N-1 se k=-1
                            */

                        x+=((matrix[(i+a+ROW)%ROW][(j+b+COL)%COL])); //x contiene la somma dei valori delle 8 celle adiacenti

                        // Condizioni di vita o morte degli organismi. Salvo la nuova generazione in una matrice temporanea
                        if ((x == 2 || x == 3) && matrix[i][j] == 1)
                            tempMatrix[i][j] = 1;
                        else if ((x < 2 || x > 3) && matrix[i][j] == 1)
                            tempMatrix[i][j] = 0;
                        else if (x == 3 && matrix[i][j] == 0)
                            tempMatrix[i][j] = 1;
                        else if ((x != 3) && matrix[i][j] == 0)
                            tempMatrix[i][j] = 0;
                    }
            }
        }

        // Riassegno alla matrice i valori contenuti nella matrice temporanea
        for(i=0; i < ROW; i++) {
            for(j=0; j < COL; j++)
                matrix[i][j] = tempMatrix[i][j];
        }

        conta = 0; // Conta il numero di organismi vivi

        // Stampo la matrice della nuova generazione
        for (i=0; i < ROW; i++) {
            for (j=0; j < COL; j++) {
                if (matrix[i][j] == 1) {
                    conta++;
                    matrix[i][j] = '#';
                }
                else
                    matrix[i][j] = ' ';
                    printf("%c", (char)matrix[i][j]);
                if (matrix[i][j] == '#')
                    matrix[i][j] = 1;
                else
                    matrix[i][j] = 0;
            }
            printf("\n");
        }

        // Stampo il numero di organismi vivi alla generazione attuale
        printf("\nOrganismi vivi: %d\n", conta);
        printf("Premere un tasto qualsiasi per interrompere il ciclo e uscire dal programma\n");

        // Se un tasto qualsiasi viene premuto, kbhit() restituisce un valore non nullo, altrimenti restituisce 0.
        if (kbhit()) // kbhit è compatibile solo con Windows
            number = 0; // Se viene premuto un tasto assegno number a 0 in modo che sia sicuramente minore di k
        // Se non viene premuto nessun tasto procedo con la pausa e la pulizia dello schermo
        else {
            sleep(1); // Pauso il sistema per un secondo (in alcune architetture l'argomento potrebbere essere in millisecondi)
            system("cls"); // Compatibile solo con Windows
        }

        // Se il numero di generazioni inserito dall'utente è diverso da 1 aumento k di un'unità
        if (number != 1)
            k++;
	}

	system("pause"); // Compatibile solo con Windows

    return 0;
}
