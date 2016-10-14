#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, nPrimi, k, i, cont;

    nPrimi = cont = 0; i=1;
    printf("Inserire il numero dei numeri primi che si vuole visualizzare: ");
    scanf("%d", &n);

    while (n <= 0) {
        printf("Errore, devi inserire un numero maggiore di zero: ");
        scanf("%d", &n);
    }
    printf("\nLista numeri primi: ");

    while (nPrimi < n) {
        i++;
        cont = 0;
        for (k=2; i >= k; k++) {
            if (i % k == 0)
                cont++;;
        }

        if (cont <= 2) {
            printf("%d  ", i);
            nPrimi++;
        }
    }

    printf("\n\n");
    system("pause");

    return 0;

}
