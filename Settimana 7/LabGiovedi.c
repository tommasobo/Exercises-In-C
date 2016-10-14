#include <stdio.h>
#include <stdlib.h>

int main()
{
    int elenco[5];
    int *ptr;

    ptr = (int*) malloc(sizeof(int) * 5);

    if (ptr == NULL) {
        printf("Errore di allocazione di memoria");
        exit(1);
    }

    return 0;
}
