#include <stdio.h>

int main()
{
    int studenti,i,voto,media,somma = 0;

    printf("Inserisci il numero di studenti:");
    scanf("%d",&studenti);

    for (i=0;i<studenti;i++) {  // Uso il ciclo for per chiedere il voto di ogni studente
        printf("Voto studente: ");
        scanf("%d",&voto);
        somma = somma + voto;
    }

    media = (somma/studenti);
    printf("\nMedia dei voti degli studenti: %d\n",media);

    return 0;
}
