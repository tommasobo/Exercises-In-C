#include <stdio.h>

int main()
{

    int vet[10] = {0}, i, j, ele, conta;

    printf("Elementi da utilizzare: ");
    scanf("%d", &ele);

    for (i=0; i < ele; i++) {
        printf("Inserisci elemento: ");
        scanf("%d", &vet[i]);
        conta = 0;
        for (j=0; j < ele; j++){
            if (vet[j] == vet[i]) {
                conta++;
            }
        }
        if (conta > 1) {
            printf("Errore, inserisci nuovamente il valore: ");
            i--;
        }


    }

    puts("");
    for (i=0; i < ele; i++)
        printf("Elementi: %d ", vet[i]);
    puts("")
;
    return 0;
}
