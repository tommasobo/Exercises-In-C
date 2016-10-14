#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define VUOTO ' '
#define NUM_COPPIE 2
#define NUM_CARTE (NUM_COPPIE * 2)

int main() {
    int stato[NUM_CARTE];
    char mazzo[NUM_CARTE];
    int i, len, index, conta;
    int carta1, carta2;

    printf("MEMORY\n\n");

    srand(time(NULL));

    for (i = 0; i < NUM_CARTE; i++) {
        stato[i] = 0;  //0 carta nascosta, 1 carta da visualizzare
        mazzo[i] = VUOTO;
    }

    /*vengono prese le prime NUM_COPPIE lettere e inserite random all'interno dell'array */
    for (i = 65, len = 65 + NUM_COPPIE; i < len; i++) {
        conta = 0;
        do {
            index = rand() % NUM_CARTE;
            if (mazzo[index] == VUOTO) {
                mazzo[index] = i;
                conta++;
            }
        }
        while (conta < 2);
    }

    carta1 = -1;
    carta2 = -1;
    conta = 0;
    do {
        system("cls");
        printf("\n");
        for (i = 0; i < NUM_CARTE; i++) {
            printf("  ");
            if (stato[i] == 1) {
                printf("%c", mazzo[i]);
            }
            else {
                printf("#");
            }
        }
        printf("\n");
        for (i = 1; i <= NUM_CARTE; i++) {
            printf("%3d", i);
        }
        if (carta1 == -1) {
            printf("\n\nseleziona 2 carte (inserisci i 2 indici separati da uno spazio): ");
            fflush(stdin);
            scanf("%d%d", &carta1, &carta2);
            carta1--;
            carta2--;
            if (carta1 >= 0 && carta1 < NUM_CARTE && carta2 >= 0 && carta2 < NUM_CARTE) {
                stato[carta1] = 1;
                stato[carta2] = 1;
            }
            else {
                printf("\n\ATTENZIONE! devi inserire due valori compresi tra 1 e %d!\n", NUM_CARTE);
                system("pause");
                carta1 = -1;
                carta2 = -1;
            }
        }
        else {//significa che è stato fatto almeno un inserimento
            if (mazzo[carta1] == mazzo[carta2]) {
                conta++;
                printf("\n\nINDOVINATO! bravo!\n");
            }
            else {
                printf("\n\nle carte selezionate non sono uguali! ritenta!\n");
                stato[carta1] = 0;
                stato[carta2] = 0;
            }
            system("pause");
            carta1 = -1;
            carta2 = -1;
        }
    }
    while(conta < NUM_COPPIE);

    printf("HAI INDOVINATO TUTTE LE CARTE!!\n\n");

    return 0;
}
