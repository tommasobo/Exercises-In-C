#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NUM_TURNI 3

int main()
{

    char opzione;
    int numero, valore;
    int conta = 0;

    do {
        srand(time(NULL)); // E' necessario usare un argomento alla funzione srand
        numero = 1 + rand() % 100; // Valori da 1 a 100
        conta = 0;
        do {
            printf("Inserisci un valore da 1 a 100: \n");
            printf("Se vuoi uscire dal programma inserisci il numero 0: ");
            scanf("%d", &valore);
            conta++;

            if (valore == 0) { //Se l'utente inserisci il valore 0, il programma viene terminato
                conta = NUM_TURNI; // exit(0) o return 0
            }

            else {
                if (numero == valore) {
                    printf("Hai indovinato il numero \n");
                    conta = NUM_TURNI; // Oppure si può usare il break ma è sconsigliato
                }
                else {
                    printf("Non hai indovinato il numero\n");
                    if (conta == NUM_TURNI) {
                        printf("Game Over, il numero da indovinare era %d \n", numero);
                    }
                    else if (numero < valore) {
                        printf("Il numero e\' piu\' piccolo di quello inserito \n\n");
                    }
                    else
                        printf("Il numero e\' piu\' grande di quello inserito \n\n");
                }
            }
        } while (conta < NUM_TURNI);

        printf("\n Vuoi fare un\' altra partita? (s/n) ");
        fflush(stdin);
        scanf("%c", &opzione);
    } while (opzione == 's' || opzione == 'S');

    return 0;
}
