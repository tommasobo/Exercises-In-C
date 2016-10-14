#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, **ptr;
    int i = 0, esci = 0, fine = 0, j, k, z;

    // Alloco lo spazio per il puntatore che punta alla prima frase
    ptr = (char**) malloc(sizeof(char*));
    if (ptr == NULL) {
        printf("Errore, memoria richiesta non disponibile");
        return 1;
    }

    printf("Inserire una frase: ");

    for (i = 0; esci != 1; i++) {
        ptr = (char**) realloc(ptr, (i+1) * sizeof(char*));
        if (ptr == NULL) {
            printf("Errore, memoria richiesta non disponibile");
            return 1;
        }

        *(ptr + i) = (char*) malloc(sizeof(char));
        if (ptr[i] == NULL) {
            printf("Errore, memoria richiesta non disponibile");
            return 1;
        }

        fine = 0;
        for (j = 0; fine != 1; j++) {
            //
            ptr[i] = (char*) realloc(ptr[i], (j+1) * sizeof(char));
            if (ptr[i] == NULL) {
                printf("Errore, memoria richiesta non disponibile");
                return 1;
            }

            c = getchar();
            if (c != '\n' && c!= ' ')
                ptr[i][j] = c;
            else if (c == '\n') {
                esci = fine = 1;
                ptr[i][j] = ' ';
            }
            else if (c == ' ') {
                fine = 1;
                ptr[i][j] = ' ';
            }
        }
        //in entrambi i casi alloco un altro elemento per contenere il carattere di terminazione \0
        j++;
        if (!(ptr[i] = (char*)realloc(ptr[i], (j+1)*sizeof(char))))
            exit(1);
            *(ptr[i]+j) = '\0';
    }

     // Stampo la frase inserita inizialmente dall'utente
    printf("\nFrase inserita dall\'utente: ");
    for (k = 0; k < i; k++) {
        for (z = 0; z < ptr[k][z]; z++)
            putchar(ptr[k][z]);
    }

    // Stampo la frase al contrario invertendo l'ordine delle parole
    printf("\nFrase stampata al contrario: ");
    for (k = i-1; k >= 0; k--) {
        for (z = 0; z < ptr[k][z]; z++)
            putchar(ptr[k][z]);
    }


    // Dealloco la memoria
    for(j=0;j<i-1;j++)
        free(ptr[j]);
    free(ptr);

    system ("pause"); // Compatibile solo con Windows

    return 0;
}

