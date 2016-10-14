/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int studenti,i,voto,somma = 0; // Inizializzo tutte le variabili assegnandoli il valore 0 per non rischiare di incorrere in errori
    float media = 0;

    do {
        printf("Inserisci il numero di studenti: ");
        scanf("%d",&studenti);
    } while (studenti <= 0); // Controllo che il numero di studenti sia positivo

    for (i=1;i<=studenti;i++) {  // Uso il ciclo for per chiedere il voto di ogni studente
        printf("\nVoto studente numero %d: ",i);
        scanf("%d",&voto);
            while (voto <18 || voto>30) { //Controllo che il voto inserito sia compreso tra 18 e 30
                printf("Errore, devi inserire un voto compreso tra 18 e 30\n");
                printf("Inserisci un nuovo voto per lo studente numero %d: ",i);
                scanf("%d",&voto);
            }

        somma = somma + voto; // Calcolo la somma dei voti
    }

    media = (float)somma/studenti; // Calcolo la media utilizzando un'operazione di casting su almeno uno dei due interi per ottenere un risultato con la virgola
    printf("\nMedia dei voti degli studenti: %g\n\n",media);

    system("pause"); // Porre attenzione perchè funziona solo con Windows

    return 0;
}
