/*Settima settimana
Esercizio 4: Si vuole gestire una sequenza (frase) di stringhe (parole) la cui dimensione non è nota a priori.
Le parole devono poter essere di lunghezza differente.
Scrivere un programma C che allochi dinamicamente le informazioni descritte e che costruisca una nuova frase in cui
l'ordine delle parole sia invertito (ad esempio, la frase “Che bella giornata” diviene “giornata bella Che”)
lavorando con i puntatori a parola.
Il programma deve visualizzare la frase prima e dopo la trasformazione.
    Eleonora Guidi
    Mat:0000691977
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {

    //dichiaro due puntatori di puntatori: uno fisso e uno temporaneo da utilizzare nelle riallocazioni
    char* *parola;

    int i, j, k, esci;

    //all'inizio alloco (e controllo) spazio per la prima parola
    if (!(parola = (char**)malloc(sizeof(char*))))
        exit(1);

    //e il primo carattere
    if (!(parola[0] = (char*)malloc(sizeof(char))))
        exit(1);

    printf("Inserisci una frase a piacere: ");

    //inizio il ciclo per scorrere tutte le parole
    for (i = 0; esci != 1; i++) {
        //inizializzo la condizione di fine ciclo a zero
        esci = 0;

        if (i > 0) {

            /* per poter allocare nuovo spazio in memoria mi serve mantenere momentaneamente
               da qualche parte l'indirizzo precedente e restituirlo in seguito al nuovo puntatore per non perdere dati */
            //alloco spazio per un altra parola
            if (!(parola = (char**)realloc(parola, (i+1)*sizeof(char*))))
                exit(1);
            //alloco un primo carattere per ogni nuova parola
            parola[i] = (char*)malloc(sizeof(char));

        }

        for (j = 0; esci == 0; j++) {

            if (j > 0) {
                //alloco spazio per un altro carattere consecutivo al primo
                //per farlo ripeto l'operazione che ho utilizzato precedentemente
                if (!(parola[i] = (char*)realloc(parola[i], (j+1)*sizeof(char))))
                    exit(1);
            }
            //acquisisco il carattere con la funzione gerchar che mi consente di inserire un carattere alla volta all'interno del puntatore
            *(parola[i]+j) = getchar();

            //se il carattere è un invio o uno spazio
            if (*(parola[i]+j) == '\n' || *(parola[i]+j) == 32 ) {

                //se il carattere è l'invio
                if (*(parola[i]+j) == '\n') {
                    //sostituisco il carattere presente con lo spazio(che servirà per poi invertirlo) e esco dal ciclo
                    *(parola[i]+j) = 32;
                    esci = 1;
                }
                else
                    //cambio la condizione di fine ciclo per iniziare a allocare una nuova parola
                    esci = 2;

                //in entrambi i casi alloco un altro elemento per contenere il carattere di terminazione \0
                j++;
                if (!(parola[i] = (char*)realloc(parola[i], (j+1)*sizeof(char))))
                    exit(1);
                *(parola[i]+j) = '\0';

            }
        }
    }

    //stampo la frase
    for (j=0; j < i; j++) {
        printf("%s", *(parola+j));
    }

    printf("\n");

    //stampo la frase al contrario
    for(j=i-1;j != -1;j--)    {
        printf("%s",*(parola+j));
    }
    printf("\n");

    //Dealloco la memoria
    for(j=0;j<i-1;j++)
        free(parola[j]);
    free(parola);

    return 0;

}
