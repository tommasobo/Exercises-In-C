#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main () {

    int n, i, j, k, l, max, min;
    int** Ptr;

    srand(time(NULL));

    printf("Inserisci un numero positivo casuale: ");
    scanf("%d", &n);

    //controllo che il numero sia positivo
    while (n < 0) {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &n);
    }

    /*puntatore di puntatori
      mantiene in memoria tutte le righe che vuole l'utente
    */
    Ptr = (int**) malloc (n * sizeof(int*));

    if (Ptr == NULL) {
        exit (1);
    }

    for (i = 0; i < n; i++) {
        //ALLOCO il puntatore da 2 a n+1
        Ptr[i] = (int*) malloc ((i + 2) * sizeof(int));

        if (Ptr[i] == NULL) {
            exit (1);
        }

        /*INIZIALIZZO il puntatore con valori random
        restringo il campo per comodita'
        */
        for (j = 0; j < i + 2; j++)
            //utilizzare *(Ptr[i] + j) equivale a *((*Ptr + i) + j)
            *(Ptr[i] + j) = rand() % MAX;
    }

    //stampo i valori inseriti
    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 2; j++)
            printf(" %d ", *(Ptr[i]+j));
        printf("\n");
    }

//_____________________________________________________ricerco il valore MASSIMO____________________________________________________
    max = 0;

    for (i = 0; i < n; i++)
        for (j = 0; j < i + 2; j++) {
            if (*(Ptr[i]+j) > max)
                max = *(Ptr[i] + j);
        }

    printf("Il massimo e\': %d\n", max);

//___________________________________________________ricerco il VALORE RIPETUTO PIU VOLTE____________________________________________

    //MAX sono tutti i numeri che potrei avere grazie alla random
    int vettore[MAX];

    for (i = 0; i < MAX; i++) {
        //inizialiazzo il vettore a 0
        vettore[i] = 0;
    }

    //scorro Ptr
    for (i = 0; i < n; i++) {
        for (j = 0; j < i + 2; j++) {
            //scorro il vettore
            for (k = 0; k < MAX; k++) {
                /*se il contenuto di Ptr equivale all'indice del vettore, incremento il vettore
                 (conto le ripetizioni di ogni valore)*/
                if (*(*(Ptr + i) + j) == k)
                        vettore[k] = vettore[k] + 1;
                else
                    vettore[k] = vettore[k];
            }
        }
    }

    //trovo il massimo del vettore che è il numero ripetuto più volte
    int max_v = 0;
    for (i = 0; i < MAX; i++) {
        if (vettore[i] > max_v)
            max_v = vettore[i];
    }

    //stampo il valore più ripetuto
    for (i = 0; i < MAX; i++) {
        if (vettore[i] == max_v)
            printf("Il valore piu\' ripetuto e\' %d per %d volte \n", i, max_v);
    }

    //libero la memoria allocata dinamicamente
    for (i = 0; i < n;i++){
        free(*(Ptr + i));
    }
    free(Ptr);

    system("pause");
    return 0;
}
