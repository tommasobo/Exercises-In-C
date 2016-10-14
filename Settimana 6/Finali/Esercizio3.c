/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ROW 1000 // Definisco il numero di righe del testo
#define COL 100 // Definisco il numero massimo di caratteri per ogni riga

int main()
{
    char text[ROW][COL+1], c;
    int i, j, k, esci, contaalnum, nc, parole,righe;

    // Richiedo all'utente di inizializzare il testo controllando che non vada oltre il numero di caratteri massimo per ogni riga
    printf("Inserisci un testo (MAX 1000 righe e 100 caratteri per riga): ");
    esci = 0;
    for(i=0; i < ROW && (esci != 1); i++) {
        if ((strcmp(text[i-1], "FINE") == 0)) {
            esci = 1; // Se viene inserita la parola "FINE", la variabile esci viene inizializzata a uno in modo da terminare il ciclo for
            righe = i - 1; // Calcolo il numero di righe inserite, togliendone una se è stata usata la parola di terminazione "FINE"
        }
        if (esci != 1) {
            for(j=0; (c = getchar()) != '\n' && (j < COL); j++) { // Continuo a memorizzare i caratteri finchè viene premuto invio o si raggiunge il massimo dei caratteri disponibili
                text[i][j] = c; // Salvo il carattere nella matrice
                righe = i;
            }
        }
        // Pulisco il buffer da eventuali caratteri rimanenti
        if(c!='\n') {
            // Se c!='\n' allora significa che non abbiamo visto '\n' nei primi COL+1 caratteri letti
            printf("\nSono stati inseriti piu\' di %d caratteri.\nSolo i primi %d sono stati considerati\n\n",COL,COL);
            // Pulisco il buffer consumando tutti i caratteri rimanenti usando un getchar
            while((c=getchar())!='\n');
        }
        // Aggiungo il carattere terminatore /0 alla fine della riga
        text[i][j]='\0';
    }

    // Calcolo il numero di caratteri, caratteri alfanumerici e parole presenti
    contaalnum = nc = parole = 0;
    for (i = 0; i <= righe; i++){
        // Uso la funzione strlen che mi restituisce la lunghezza della stringa
        nc += strlen(text[i]); // Calcolo la lunghezza delle stringhe per tutte le righe
        for (k=0; (unsigned)k < (strlen(text[i])); k++) { //Trasformo k in unsiged in modo da evitare eventuali warnings del compilatore
            if (isalnum(text[i][k])) { // Controllo se il carattere è alfanumerico
                contaalnum++;
                // Controllo se il carattere successivo può indicare che la parola è terminata. Sono stati inclusi i caratteri più comuni
                // Considero anche i numeri o le lettere singole delle parole
                if (text[i][k+1] == ' ' || text[i][k+1] == '.' || text[i][k+1] == ',' || text[i][k+1] == '?' || text[i][k+1] == '\0')
                    parole++;
            }
        }
    }

    // Stampo a video i dati ottenuti
    // Nel conto della riga viene esclusa la riga "FINE"
    // Nel conto dei caratteri e delle parole viene inclusa la stringa "FINE".
    printf("\nRighe usate nel testo: %d", righe);
    printf("\nCaratteri usati nel testo: %d",nc);
    printf("\nCaratteri alfa numerici presenti nel testo: %d",contaalnum);
    printf("\nParole presenti nel testo: %d\n\n",parole);

    system("pause"); // Compatibile solo con Windows

    return 0;
}
