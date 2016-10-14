//aggiunto controllo valore di ritorno della scanf e aggiunte stampe usando varie notazioni (linea 69)

#include <stdio.h>
#include <stdlib.h>

int main () {

    int voti[200];
    int* ptr;
    int indice[200];

    int n, studenti, controllo;


    ptr = &voti[0];  //punta al primo elemento

    printf("Inserire numero studenti: ");
    controllo = scanf("%d", &studenti);

    // Controllo che gli studenti non superino la dimensione del vettore
    while (studenti > 200 || controllo != 1) {
        fflush(stdin);
        printf("Inserire un numero di studenti valido: (max 200) \n");
        controllo = scanf("%d", &studenti);
    }

    for (n = 0; n < studenti; n++) {
        printf("Inserire il voto dello studente numero %d: (compreso tra 18 e 30) ", n + 1);
        controllo = scanf ("%d", &voti[n]);

        //controllo che il voto sia compreso tra 18 e 30
        while (voti[n] < 18 || voti[n] > 30 || controllo != 1) {
            fflush(stdin);
            printf("Inserire un voto valido: (compreso tra 18 e 30) ");
            controllo = scanf ("%d", (voti + n)); //Salvo usando l'aritmetica dei puntatori applicata al nome del vettore (indirizzo memoria primo elemento)
        }
    }

    /*  Inizializzo il vettore utilizzando i puntatori
    for (i=0; i<studenti; i++) {
        printf("Inserire il voto dello studente numero %d: (compreso tra 18 e 30) ", i+1);
        scanf ("%d", ptr+i);


        //controllo che il voto sia compreso tra 18 e 30
        while (*(ptr+i)<18 || *(ptr+i)>30) {
            printf("Inserire un voto valido: (compreso tra 18 e 30) ");
            scanf ("%d", ptr+i);
        }
    }
    */



    for (n = 0; n < studenti; n++) {
        indice[n] = n + 1;
    }

    printf("|indice | Vettore | Puntatore\n");  //stampo indice dei voti


    for (n = 0; n < studenti; n++) {
        printf("|   %d    |   %d    |   %d  |   \n", indice[n], voti[n], *(ptr + n)); // Stampo una volta i voti con l'indice degli array e una volta con i puntatori
    }


    printf("\n\nStampo col secondo metodo:\n");
    for (n = 0; n < studenti; n++) {
        printf("|   %d    |   %d    |   %d  |   \n", indice[n], *(voti + n), ptr[n]); //Stampo usando aritmetica dei puntatori applicata all'array e indici vettoriali applicati ai puntatori
    }



    system ("pause");
    return 0;
}
