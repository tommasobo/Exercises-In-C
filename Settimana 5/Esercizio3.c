/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100 // Definisco la dimensione massima della matrice

int main()
{
    short int matrice[MAX][MAX], i, j, n, k, conta;
    int vet[(MAX*2)+2]; // Definisco la dimensione massima dell'array vet che conterrà le varie somme

    // Richiedo dimensione matrice
    printf("Inserisci il numero di righe e colonne della matrice quadrata: ");
    scanf("%hd", &n);

    // Controllo che la dimensione inserita dall'utente sia valida (>0)
    while (n <= 0 || n > 100) {
		printf("Errore, devi inserire un valore intero compreso tra 1 e 100: ");
		scanf("%hd", &n);
	}

    // Richiedo all'utente di inizializzare la matrice
    for (i=0; i < n; i++)
        for (j=0; j < n; j++) {
            printf("Inserisci dato coordinate (%d;%d): ",i,j);
            scanf("%hd", &matrice[i][j]);
            while (matrice[i][j] <= 0) { // Controllo che il valore inserito sia positivo
				printf("Errore, devi inserire un valore positivo: ");
				scanf("%hd", &matrice[i][j]);
			}
        }

    // Stampo la matrice
    printf("\n\n ----- Matrice -----\n");
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            printf("%4hd ", matrice[i][j]);
        }
        puts("");
    }

    // Salvo la somma delle righe in un array chiamato vet3
    for (i=0; i < n; i++) {
        for (j=0; j < n; j++) {
            vet[i] += matrice[i][j];
        }
        k = i;
    }

    // Salvo la somma delle righe nell'array vet3 partendo dall'elemento i+n
    for (j=0; j < n; j++) {
        for (i=0; i < n; i++) {
            vet[i+n] += matrice[j][i];
        }
    }

    // Salvo la somma dei valori presenti nella diagonale principale nell' array vet 3 partendo da (n*2)+1
    for (i=0; i < n; i++) {
        vet[(n*2)] += matrice[i][i];
    }

    // Salvo la somma dei valori presenti nella diagonale secondaria nell'array vet3 partendo da (n*2)+2
    for (i=(n-1); i >= 0; i--) {
        vet[((n*2)+1)] += matrice[i][i];
    }


	// Controllo se gli elementi di vet3 sono tutti uguali. Se almeno uno è diverso dal precedente incremento la variabile conta
    conta = 0;
    k = (n * 2) + 2;
    for (i=1; i < k;i++) {
        if (vet[i] != vet[i-1])
            conta++;
        }

	// Se la variabile conta è pari a 0 e quindi tutti gli elementi di vet3 sono uguali, stampo che il quadrato considerato è magico
    if (conta < 1)
        printf("\n\nResoconto: il qudrato inserito e\' magico\n\n");
    else
        printf("\n\nResoconto: il quadrato inserito non e\' magico\n\n");

	system("pause"); // Compatibile solo con Windows

	return 0;

}
