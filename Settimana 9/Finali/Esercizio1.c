/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Scrivere un programma C che risolva il problema delle torri di Hanoi
      tramite l'implementazione di una funzione ricorsiva. Immettere il valore n da riga di comando.
      Stampare in maniera significativa la sequenza di comandi per lo spostamento dei dischi sui
      paletti, indentando opportunamente le chiamate in modo da chiarire il funzionamento della
      ricorsione.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h> // Includo la libreria math.h per l'uso della funzione esponenziale

// Prototipo della funzione che utilizzerò
void move(int n, char from, char to, char temp);

int main() {

    int n, check;
    char ch;

    printf("\t\t ---- TORRI DI HANOI ---- \n\n");
    printf("Inserire numeri maggiori di 10 puo\' richiedere molto tempo per il completamento delle operazioni");
    printf("\nInserisci il numero di dischi con cui giocare: ");
    // Controllo che il numero inserito dall'utente sia un intero positivo
    check = scanf("%d", &n);
    while ((ch = getchar() != '\n') && (ch != EOF)); // Pulisco il buffer
    while (n <= 0 || n > INT_MAX || check != 1) {
        printf("Errore, devi inserire un numero valido maggiore di 0: ");
        check = scanf("%d", &n);
        while ((ch = getchar() != '\n') && (ch != EOF)); // Pulisco il buffer
    }

    printf("Numero mosse necessarie: %g \n",(pow(2, n) - 1)); // Calcolo il numero di mosse necessarie a risolvere il problema di Hanoi

    move (n, '1', '2', '3'); //Chiamo la funzione move

    system ("pause"); // Compatibile solo con Windows
    return 0;
}

/* I parametri di questa funzione indicano:
    * il numero di dischi da spostare
    * il primo paletto (quello di sinistra) con from
    * il secondo paletto (quello di centro) con temp
    * il terzo paletto (quello di destra) con to */
void move (int n, char from, char to, char temp) {

	static int indent = -1; // Dichiaro una variabile statica in modo che il suo indirizzo di memoria non cambi durante le varie ricorsioni
	int i;

    if (n == 0) // Se non ci sono più dischi da spostare la funzione esce (viene chiamato passo base)
        return;
    else {
         /* All'avvio di una funzione ricorsiva aumenta il valore, alla chiusura lo diminuisce, in questo modo ogni operazione ha
            un'indentazione maggiore se ha una ricorsione di profondità maggiore */
        indent++;
        /* Con la prima ricorsione spostiamo tutti i dischi tranne l'ultimo dalla propria posizione verso la destinazione temporanea. */
        move (n-1, from, temp, to);
        for (i=0;i<indent;i++)
			printf("  ");
        /* sposta il disco n-esimo dall’origine alla destinazione */
        printf("Sposta il disco %d dalla torre numero %c alla numero %c \n", n, from, to);
        /* sposta n-1 dischi dalla sosta temporanea alla destinazione*/
        move (n-1, temp, to, from);
        indent--; // Diminuisco l'indentazione
    }
}
