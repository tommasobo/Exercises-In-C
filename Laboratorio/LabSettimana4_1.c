#include <stdio.h>

int main ()
{
    int vettore[10], cifre, i, somma;
    float media;

    printf("Quanti numeri vuoi inserire? ");
    scanf ("%d", &cifre);

    while (cifre > 10 || cifre <= 0) {
        printf("Errore, devi inserire un numero compreso tra 1 e 10: ");
        scanf("%d", &cifre);
    }

    for (i=1; i <= cifre; i++) {
        printf("Inserisci il valore numero %d: ", i);
        scanf("%d", &vettore[i]);
    }

    somma = 0;
    for (i=1; i <= cifre; i++)
        somma = somma + vettore[i];
    printf("\nLa somma e\': %d \n", somma);

    media = ((float)somma / cifre);
    printf("La media e\': %g \n", media);

}
