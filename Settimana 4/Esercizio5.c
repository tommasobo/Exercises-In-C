/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>

int main()
{
    int n, nPrimi, divisore, i, cont;

    printf("Inserire il numero dei numeri primi che si vuole visualizzare: ");
    scanf("%d", &n);

    while (n <= 0) { // Controllo che il numero inserito sia positivo e in caso contrario lo richiedo all'utente
        printf("Errore, devi inserire un numero maggiore di zero: ");
        scanf("%d", &n);
    }
    printf("\nLista numeri primi: "); // Nota: il numero 1 non � un numero primo

    nPrimi = 0; // Inizializzo la variabile nPrimi che verr� usata per contare i numeri primi trovati
    i = 1; // Il numero i � quello si cui si andr� a fare il controllo per verificare se � primo o meno

    /*
       Eseguo il ciclo while finch� il numero dei numeri primi trovato � uguale a quello inserito inizialmente
       dall'utente (notare che si usa il simbolo minore perch� la variabile nPrimi parte da 0)
    */
    while (nPrimi < n) {
        i++; // Ogni volta che inizia il ciclo while incremento di uno il numero i di cui si vuole verificare se sia primo o meno.
        cont = 0; // La variabile cont mi permetter� di capire quante volte la divisione tra i e divisore ha come resto 0
        /*
            Se la divisione tra i e 2 ha come resto 0 e se i � maggiore di 2, allora siamo sicuri che il numero i non � primo.
            Eseguire questa operazione permette di non eseguire il ciclo for che � molto pi� lento e pesante in termini di memoria
        */
        if (i % 2 == 0 && i > 2)
            cont += 2; // Per far capire al programma che non si tratta di un numero primo aumento la variabile cont di due unit�
        /*
            Se non � divisibile per due e se quindi non � pari sono costretto ad usare un ciclo for che verifica se il numero i
            � primo andando a verificare il resto della divisione tra i e tutti i numeri compresi tra due e i. Per eseguire questa
            operazione si usa una variabile divisore
        */
        else {
            for (divisore=2; i >= divisore; divisore++) {
                if (i % divisore == 0)
                    cont++; // Se la divisione tra i e divisore ha resto 0, incremento di uno la variabile cont
            }
        }
        if (cont < 2) { // Se cont � minore di 2 perch� solo una volta la divisione con divisore ha dato resto 0, alora esso � sicuramente primo
            printf("%d  ", i);
            nPrimi++; // Se stampo un numero primo incremento di uno la variabile nPrimi
        }
    }

    printf("\n\n");
    getchar();

    return 0;

}
