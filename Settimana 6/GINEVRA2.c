#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int main ()
{
    char stringa[MAX+1];
    int caratteri, i, vocali, consonanti, conta[26] = {0}, x, conta1[26] = {0};

    printf("Inserisci una stringa a piacere.\nEventuali caratteri oltre i 100 saranno ignorati: \n");
    scanf("%100s", stringa);

    // Lunghezza stringa
    caratteri = strlen(stringa);

    // Scorro l'array carattere per carattere dividendoli tra vocali o consonanti
    vocali = consonanti = 0;
    for (i = 0; i < caratteri; i++) {
        if ( stringa[i] >= 97 && stringa[i] <= 122) {
            conta[stringa[i] - 97]++;
            if (stringa[i]=='a' || stringa[i]=='e' || stringa[i]=='i' || stringa[i]=='o' || stringa[i]=='u')
                vocali++;
            else
                consonanti++;
        }
    }

    // Faccio lo stesso per le maiuscole
    for (i = 0; i < caratteri; i++) {
        if ( stringa[i] >= 65 && stringa[i] <= 90) {
            conta1[stringa[i] - 65]++;
            if (stringa[i]=='A' || stringa[i]=='E' || stringa[i]=='I' || stringa[i]=='O' || stringa[i]=='U')
                vocali++;
            else
                consonanti++;
        }
    }

    printf("\n");
    // Stampo il risultati
    for (x = 0; x < 26; x++)
        printf("La lettera %c compare %d volte\n",x + 97,conta[x]);

    printf("\n\n");

    for (x = 0; x < 26; x++)
        printf("La lettera %c compare %d volte\n",x + 65,conta1[x]);

    printf("\n\nLe vocali sono: %d\n", vocali);
    printf("Le consonanti sono: %d\n", consonanti);


    system ("pause"); // Funziona solo su Windows

    return 0;
}
