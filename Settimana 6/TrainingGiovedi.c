#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *ptr, *ptrnew, n, i;

    printf("Quanti interi vuoi allocare? ");
    scanf("%d", &n);

    ptr = (int *)malloc(n*sizeof(int)); //malloc restituisce un puntatore a void se non utilizziamo un cast
    if (ptr == NULL)
        printf("Errore nell'allocazione di memoria");
    else {
        for (i = 0; i < n; i++) {
            printf("Inserisci il valore %d): ",(i+1));
            scanf("%d", (ptr+i));
        }
    ptrnew = ptr;

        printf("\nValori inseriti: ");
        for (i = 0; i < n; i++)
            printf("%d ", *(ptr+i));
    }

    free(ptr);



    return 0;
}
