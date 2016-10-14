/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int col,row,ic,ir,check = 0;

    do { // Utilizzo un ciclo "do while" per controllare che il numero inserito dall'utente sia maggiore di 0 e che si tratti di un numero.
        printf("Inserisci il numero di righe (deve essere positivo): ");
        check = scanf("%d",&row); // La funzione scanf mi restituisce un valore. Se esso è 1 significa che il dato è stato letto correttamente
        fflush(stdin); // Pulisco il buffer. Prestare attenzione in quanto è compatibile solo con Windows
    }while (row <= 0 || check != 1); // Condizione affinchè si ripeta il ciclo
    do { // Eseguo lo stesso controllo sul numero di colonne
        printf("Inserisci il numero di colonne (deve essere positivo): ");
        check = scanf("%d",&col);
        fflush(stdin);
    } while (col <= 0 || check != 1);

    printf("\nTavola pitagotica della moltiplicazione usando il ciclo for\n");
    printf("X\t"); // Riempio il primo carattere della tabella con una X
    for (ic=0; ic<col; ic++){ // Stampo la prima riga della tavola pitagorica partendo da 0
                printf("%d\t",ic);
        }
    printf("\n");

    for (ir=0; ir<row; ir++) {  // Risolvo l'esercizio con il ciclo for
            printf("%d\t",ir); // Stampo la prima colonna della tavola pitagorica partendo da 0
        for (ic=0; ic<col; ic++){
                printf("%d\t",ic*ir); // Calcolo i valori della tavola pitagorica
        }
        printf("\n");
    }


    printf("\nTavola pitagotica della moltiplicazione usando il ciclo while\n");
    ir = 0;
    printf("X\t"); // Riempio il primo carattere della tabella con una X
    for (ic=0; ic<col; ic++){
                printf("%d\t",ic);
        }
        printf("\n");
    while (row>ir)  // Risolvo l'esercizio con il ciclo while
    {
        ic = 0;
         printf("%d\t",ir);

        while (col>ic)
        {
            printf("%d\t",ic*ir);
            ic++; // Ogni volta che viene ripetuto il ciclo aumento di uno il valore delle colonne
        }
        printf("\n");
        ir++; // Ogni volta che viene ripetuto il ciclo aumento di uno il valore delle righe
    }


    printf("\n\nTavola pitagotica della somma usando il ciclo for\n");
    printf("X\t"); // Riempio il primo carattere della tabella con una X
    for (ic=0; ic<col; ic++){ // Stampo la prima riga della tavola pitagorica partendo da 0
                printf("%d\t",ic);
        }
    printf("\n");

    for (ir=0; ir<row; ir++) {  // Risolvo l'esercizio con il ciclo for
            printf("%d\t",ir); // Stampo la prima colonna della tavola pitagorica partendo da 0
        for (ic=0; ic<col; ic++){
                printf("%d\t",ic+ir); // Calcolo la somma tra riga e colonna per trovare il valore da stampare
        }
        printf("\n");
    }

    printf("\nTavola pitagotica della somma usando il ciclo while\n");
    ir = 0;
    printf("X\t");
    for (ic=0; ic<col; ic++){
                printf("%d\t",ic);
        }
        printf("\n");
    while (row>ir)  // Uso il ciclo while in modo analogo a prima solo sommando i valori al posto di moltiplicarli
    {
        ic = 0;
         printf("%d\t",ir);

        while (col>ic)
        {
            printf("%d\t",ic+ir);
            ic++;
        }
        printf("\n");
        ir++;
    }

    system("pause"); //Compatibile solo con Windows

    return 0;
}
