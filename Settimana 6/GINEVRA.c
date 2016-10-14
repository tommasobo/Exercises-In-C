#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define RIGHE 1000
#define max_caratteri 100

int main()
{
    char testo[RIGHE][max_caratteri], text;
    int i = 0, j = 0, righe = 0, lunghezza = 0, carattere = 0, parola = 0;

    printf("Inserisci il tuo testo. \n");
    printf("Per cambiare riga premi invio. \n Puoi inserire al massimo %d righe. \nOgni riga puo\' contenere al massimo %d caratteri. \n", RIGHE, max_caratteri);
    printf("Per terminare l'inserimento del testo scrivi 'FINE'.\n\n");

    //strcmp confronta la stringa appena inserita con quella utilizzata per l'uscita dal ciclo, cioè FINE
    //ho deciso di aggiungere anche 'fine' in minuscolo in modo da fare uscire comunque l'utente dal ciclo
    for(i=0; strcmp(testo[i-1], "FINE") && strcmp(testo[i-1], "fine") ; i++) {

        //utilizzo (max_caratteri - 1) per mantenere uno spazio libero per il carattere di escape /0
        for(j=0; (text = getchar()) != '\n' && i<(max_caratteri-1); j++) {
            testo[i][j] = text;
        }

        //getchar non utilizza il buffer, ma inserisce un carattere per volta all'interno della riga.
        //quindi devo aggiungere il carattere di escape /0 per fargli capire che la riga è finita
        testo[i][j]='\0';
    }

    //(i-1) perchè devo togliere la riga "fine"
    righe = i-1;

    printf("\n\n\n");

    //conto i caratteri riga per riga
    for (i = 0; i < righe; i++) {
        lunghezza = lunghezza + strlen(testo[i]);

        //faccio un secondo ciclo per contare i caratteri alfanumerici e le parole
		for (j = 0; j < strlen(testo[i]);j++) {

            //uso la codifica ASCII relativa a numeri e lettere
			if((testo[i][j] >= 41 && testo[i][j] <= 90) || (testo[i][j] >= 97 && testo[i][j] <= 122 )||(testo[i][j] >= 48 && testo[i][j] <= 57 )) {
				carattere++;

                //uso la codifica ASCII di tutti gli altri simboli
                if((testo[i][j+1] <= 48) || (testo[i][j+1] >= 58 && testo[i][j+1] <= 64)  || (testo[i][j+1] >= 91 && testo[i][j+1] <= 96) || (testo[i][j+1] >= 126)) {
					parola++;
				}

			}

		}
	}

    //stampo tutti i risultati richiesti
    printf("Il testo e\' composto da %d righe, ", righe);
    printf("%d caratteri ", lunghezza );
    printf("(di cui %d alfanumerici), ", carattere);
    printf("suddivisi in %d parole. \n", parola);

    system("pause");
    return 0;

}
