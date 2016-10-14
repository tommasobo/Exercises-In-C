//
//  Esecizio2.c
//
//  Creato da Alberto Giunta il 30/11/13.
//  Maticola: 0000691428

/*Sviluppare un programma che simuli un mescolatore (tramite un’apposita funzione) e un distributore (altra funzione) delle cinque carte di una mano di poker.
 Implementare poi una funzione che determini se la mano contiene una coppia, una doppia coppia, un tris, un poker, un colore o una scala.
 Utilizzare le funzioni per sviluppare un programma che gestisca un’intera partita il cui funzionamento è di seguito descritto:
 Il gioco richiede un mazzo di carte dal quale il mazziere distribuisce cinque carte a ogni giocatore.
 Ogni giocatore può cambiare da una a quattro carte, in modo da ottenere nuove combinazioni.
 Ogni giocatore ha la facoltà di puntare una cifra o di abbandonare la mano.
 Si procede alla verifica delle combinazioni e alla nomina del vincitore.
 Vince chi ottiene la combinazione di maggiore valore o induce tutti gli altri giocatori ad abbandonare la partita.
 Le combinazioni di maggior valore in ordine decrescente sono:
 •	Poker
 •	Colore
 •	Full
 •	Scala
 •	Tris
 •  Doppia Coppia
 •	Coppia
 •	La carta più alta
 Ogni eventuale miglioria è, come sempre, bene accetta.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

typedef struct card {
	int num;
	int seme;
}carta;

typedef struct gioc {
	carta mano[5];
	int cash;
	carta cartaAlta;
	carta cartaAltaMano;
	int fold;
	int puntata;
}giocatore;

int *punteggi;
/* valore per combinazione
 0 » coppia
 1 » doppia coppia
 2 » tris
 3 » scala
 4 » full
 5 » colore
 6 » poker
*/

//variabili globali
int estrazione = 0, puntataPrec = 0, contaMano = 0, contaVedi = 0, contaFold = 0, contaKO = 0;

void stampaDivisorio();
carta mescolaMazzo(carta mazzo[4][13]);
carta distribuisciCarta(carta mazzo[4][13]);
giocatore ordinaMano(giocatore *gioc, int i);
giocatore cambiaCarte(giocatore *gioc, int i, carta mazzo[4][13]);
void stampaMano (giocatore *gioc, int numGioc);
void trovaMassimo (giocatore *gioc, int numGioc);
void analizzaMano (giocatore *gioc, int numGioc);
int puntaVedi (giocatore *gioc, int numGioc);
int vincitore (giocatore *gioc, int numGioc, int piatto);
int mano (giocatore *gioc, int numGioc, carta mazzo[4][13]);

int main() {

	srand((unsigned int)time(NULL));

	carta mazzo[4][13];
	int i, j;
	int soldi;

	/*riempio il mazzo*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 13; j++) {
			mazzo[i][j].num = j + 1;
			switch (i) {
				case 0:
					mazzo[i][j].seme = i; //quadri
					break;
				case 1:
					mazzo[i][j].seme = i; //cuori
					break;
				case 2:
					mazzo[i][j].seme = i; //fiori
					break;
				case 3:
					mazzo[i][j].seme = i; //picche
			}
		}
	}

	/*prendo in input il numero di giocatori*/
	int numGioc;

	printf("In quanti si vuole giocare?\n");
	do {
		fflush(stdin);
		printf("							» ");
	} while (scanf("%d", &numGioc) != 1 || numGioc < 2 || numGioc > 5);
	giocatore *gioc = (giocatore*)malloc(sizeof(giocatore) * numGioc);
	punteggi = (int*)malloc(sizeof(int) * numGioc);

	if (gioc == NULL || punteggi == NULL) {
		printf("Memoria non sufficiente!");
	}


	/*prendo in input il portafogli iniziale di ogni giocatore*/
	printf("Con quanto desiderate giocare?\n");
	do {
		fflush(stdin);
		printf("							» € ");
	} while (scanf("%d", &soldi) != 1 || soldi < 1);

	for (i = 0; i < numGioc; i++) {
		gioc[i].cash = soldi;
	}

	stampaDivisorio();


	int win;
	int contaKO = numGioc;
	while (contaKO > 1) {
		win = mano(gioc, numGioc, mazzo);
	}
	printf("Giocatore %d vince la partita.", win);
	printf("\n\n");

	free(punteggi);
	free(gioc);
	return 0;
}

void stampaDivisorio() {
	printf("\n___________________________________________________________________________________\n");
}

carta mescolaMazzo(carta mazzo[4][13]) {
	int i, j, semeRand, numRand;
	carta temp;


	for (i = 0; i < 4; i++) {
		for (j = 0; j < 13; j++) {
			semeRand = rand() % 4;
			numRand = rand() % 13;

			temp = mazzo[i][j];
			mazzo[i][j] = mazzo[semeRand][numRand];
			mazzo[semeRand][numRand] = temp;
		}
	}
	return mazzo[4][12];
} //mescola mazzo OK

carta distribuisciCarta(carta mazzo[4][13]) {

	//estrazione è la prima carta del mazzo, quella che verrà distribuita

	carta temp;

	if (estrazione >=0 && estrazione < 13) {
		temp = mazzo[0][estrazione];
	}
	if (estrazione >= 13 && estrazione < 26) {
		temp = mazzo[1][estrazione - 13];
	}
	if (estrazione >= 26 && estrazione <39) {
		temp = mazzo[2][estrazione - 26];
	}
	if (estrazione >= 39 && estrazione < 52) {
		temp = mazzo[3][estrazione - 39];
	}

	estrazione++;

	return temp;
} //distribuisci carte OK

giocatore ordinaMano(giocatore *gioc, int numGioc) {

	carta swap;
	int i, j;

//	/*bubblesort*/
	for (i = 4; i > 0 ; i--) {
		for (j = 1; j <= i; j++) {
			if (gioc[numGioc].mano[j].num < gioc[numGioc].mano[j - 1].num) {
				swap = gioc[numGioc].mano[j - 1];
				gioc[numGioc].mano[j - 1] = gioc[numGioc].mano[j];
				gioc[numGioc].mano[j] = swap;
			}
		}
	}
	return gioc[numGioc];
} //ordina OK

giocatore cambiaCarte (giocatore *gioc, int numGioc, carta mazzo[4][13]) {
	int numCambi, i, indiceCarta;

	stampaMano (gioc, numGioc);

	printf("\nQuante carte vuoi cambiare?\n");
	do {
		fflush(stdin);
		printf("									» ");
	} while (scanf("%d", &numCambi) != 1 || numCambi < 0 || numCambi > 4);

	if (numCambi != 0) {
		for(i = 0; i < numCambi; i++) {
			printf("\nInserire posizione della carta da cambiare nella mano (1 - 5)\n");
			do {
				fflush(stdin);
				printf("											» ");
			} while(scanf("%d", &indiceCarta) != 1 || indiceCarta < 1 || indiceCarta > 5);
			gioc[numGioc].mano[indiceCarta -1] = distribuisciCarta(mazzo);
		}
		stampaMano (gioc, numGioc);
	}
	stampaDivisorio();
	return gioc[numGioc];
} //cambia carte OK

void stampaMano (giocatore *gioc, int numGioc){
	int i;
	printf("\nGIOCATORE %d\n", numGioc + 1);
	puts("\nLa tua mano è:");
	for (i = 0; i < 5; i++) {
		printf("%d° carta: ", i + 1);
		switch (gioc[numGioc].mano[i].num) {
			case 11:
				printf(" J "); //JACK
				break;
			case 12:
				printf(" Q "); //DONNA
				break;
			case 13:
				printf(" K "); //RE
				break;
			default:
				printf("%2d ", gioc[numGioc].mano[i].num);
				break;
		}


	    switch (gioc[numGioc].mano[i].seme) {
		   case 0:
			   printf("Quadri\n"); //quadri
			   break;
		   case 1:
			   printf("Cuori\n"); //cuori
			   break;
		   case 2:
			   printf("Fiori\n"); //fiori
			   break;
		   case 3:
			   printf("Picche\n"); //picche
		}
	}
}

void analizzaMano (giocatore *gioc, int numGioc) {
	int i = 0;
	int conta = 0;

	ordinaMano(gioc, numGioc);

	//conteggio per combinazioni di carte con valori uguali tra loro
	for (i = 0; i < 4; i++) {
		if (gioc[numGioc].mano[i].num == gioc[numGioc].mano[i + 1].num) {
			conta++;
		} else {
			if (punteggi[numGioc] == -1) { //se non ha mai trovato niente

				if (conta == 1) {
					punteggi[numGioc] = 0; //coppia
					gioc[numGioc].cartaAlta.num = gioc[numGioc].mano[i].num;
					gioc[numGioc].cartaAlta.seme = gioc[numGioc].mano[i].seme;

				} else if (conta == 2) {
					punteggi[numGioc] = 2; //tris
					gioc[numGioc].cartaAlta.num = gioc[numGioc].mano[i].num;
					gioc[numGioc].cartaAlta.seme = gioc[numGioc].mano[i].seme;

				} else if (conta == 3) {
					punteggi[numGioc] = 6; //poker
					gioc[numGioc].cartaAlta.num = gioc[numGioc].mano[i].num;
					gioc[numGioc].cartaAlta.seme = gioc[numGioc].mano[i].seme;
				}

			} else {
				if (punteggi[numGioc] == 0 && conta == 1) {
					punteggi[numGioc] = 1; //doppia coppia
					//assegno carta alta
					gioc[numGioc].cartaAlta.num = gioc[numGioc].mano[i].num;
					gioc[numGioc].cartaAlta.seme = gioc[numGioc].mano[i].seme;

				} else if ((punteggi[numGioc] == 0 && conta == 2) || (punteggi[numGioc] == 2 && conta == 1)) {
					punteggi[i] = 4; //full
					//assegno carta alta
					gioc[numGioc].cartaAlta.num = gioc[numGioc].mano[i].num;
					gioc[numGioc].cartaAlta.seme = gioc[numGioc].mano[i].seme;
				}
			}
			conta = 0;
		}

	}
	//conteggio per carte tutte di valore diverso tra loro

	//scala
	conta = 0;
	int next = 0;
	for (i = 0; i < 4; i++) {
		next = gioc[numGioc].mano[i + 1].num;
		if (gioc[numGioc].mano[i].num == next - 1) {
			conta++;
		}
	}
	if (conta == 4) {
		punteggi[numGioc] = 3; //scala
	}

	//colore
	conta = 0;
	for (i = 0; i < 4; i++) {
		if (gioc[numGioc].mano[i].seme == gioc[numGioc].mano[i + 1].seme) {
			conta++;
		}
	}
	if (conta == 4) {
		punteggi[numGioc] = 5; //colore
	}
}

int puntaVedi (giocatore *gioc, int numGioc) {
	int scelta, puntata = 0;
	ordinaMano(gioc, numGioc);
	stampaMano (gioc, numGioc);
	printf("\nIl tuo portafogli attuale è: €%d\n", gioc[numGioc].cash);
	printf("\nCosa vuoi fare?\n");
	printf("1 » Rilancia\n");
	printf("2 » Vedi\n");
	printf("3 » Lascia\n");

	do {
		fflush(stdin);
		printf("		» ");
	}while (scanf("%d", &scelta) != 1 || (scelta < 1 || scelta > 3));

	switch (scelta) {
			//punta
		case 1:
			printf("Quanto vuoi puntare?\n");
			do {
				fflush(stdin);
				printf("		» € ");
			}while (scanf("%d", &puntata) != 1 || puntata < 1 || puntata > gioc[numGioc].cash || puntata <= puntataPrec);
			contaVedi = 0;
			puntataPrec = puntata;
			gioc[numGioc].puntata = puntata;
			gioc[numGioc].cash -= puntata;
			if (gioc[numGioc].cash <= 0) {
				printf("Non hai più soldi, sei andato in ALL IN\n");
			} else {
				printf("Rilanci. Hai puntato €%d, ti rimangono €%d\n", puntata, gioc[numGioc].cash);
			}
			break;
			//vedi
		case 2:
			contaVedi++;
			if (puntataPrec != gioc[numGioc].puntata) {
				gioc[numGioc].cash -= puntataPrec;
			} else {
				puntataPrec = 0;
			}
			printf("Vedi. Hai puntato €%d, ti rimangono €%d\n", puntataPrec, gioc[numGioc].cash);
			if (gioc[numGioc].cash <= 0) {
				printf("Non hai più soldi, sei andato in ALL IN\n");
			}
			puntata = puntataPrec;
			break;
		case 3:
			//folda
			printf("Hai lasciato la mano.");
			gioc[numGioc].fold = TRUE;
			puntata = 0;
			contaFold++;
			break;
	}

	stampaDivisorio();
	return puntata;
}

int vincitore (giocatore *gioc, int numGioc, int piatto) {
	int i;
	int max = 0 ;

	for (i = 1; i < numGioc; i++) {
		if (gioc[i].fold == FALSE) {
			if (punteggi[i] == punteggi[max]) { //se sono la stessa figura
				if (gioc[i].cartaAlta.num > gioc[max].cartaAlta.num) { //se il valore di i > max
					max = i;
				} else if (gioc[i].cartaAlta.num == gioc[max].cartaAlta.num) { //se hanno lo stesso valore di figura
					if (gioc[i].cartaAltaMano.num > gioc[max].cartaAltaMano.num) { //se la carta alta della mano i > max
						max = i;
					}
				}
			} else if (punteggi[i] > punteggi[max]) {
				max = i;
			}
		}
	}

	gioc[max].cash += piatto;

	stampaDivisorio();
	printf("Giocatore %d hai vinto!\n", (max + 1));
	if (piatto == 0) {
		printf("Però purtroppo non hai guadagnato nulla :(");
	} else {
		printf("Hai guadagnato €%d!\n", piatto);
	}
	stampaMano(gioc, max);

	//dichiarazione della combinazione vincente
	switch (punteggi[max]) {
		case 0:
			printf("Coppia di %d", gioc[max].cartaAlta.num);
			break;
		case 1:
			printf("Doppia coppia con coppia alta di %d", gioc[max].cartaAlta.num);
			break;
		case 2:
			printf("Tris di %d", gioc[max].cartaAlta.num);
			break;
		case 3:
			printf("Scala di massimo %d", gioc[max].cartaAlta.num);
			break;
		case 4:
			printf("Full di carta alta %d", gioc[max].cartaAlta.num);
			break;
		case 5:
			printf("Colore di carta alta %d", gioc[max].cartaAltaMano.num);
			break;
		case 6:
			printf("Poker di %d", gioc[max].cartaAlta.num);
			break;
	}
	stampaDivisorio();
	return max;
}

int mano (giocatore *gioc, int numGioc, carta mazzo[4][13]) {
	int i, j;

	/*mescolo le carte*/
	mescolaMazzo(mazzo);

	/*azzero i punteggi e i fold*/
	for (i = 0; i < numGioc; i++) {
		*(punteggi + i) = -1;
		gioc[i].fold = FALSE;
	}

	/*distribuisci carte*/
	for (i = 0; i < 5; i++) {
		for (j = 0; j < numGioc; j++) {
			gioc[j].mano[i] = distribuisciCarta(mazzo);
		}
	}

	/*ordina mano*/
	for (i = 0; i < numGioc; i++) {
		gioc[i] =  ordinaMano(gioc, i);
	}

	/*cambia carte*/
	for (i = 0; i < numGioc; i++) {
		gioc[i] = cambiaCarte(gioc, i, mazzo);
	}

	//trova massimo nella mano
	for (i = 0; i < numGioc; i++) {
		gioc[i].cartaAltaMano.num = gioc[i].mano[4].num;
		gioc[i].cartaAltaMano.seme = gioc[i].mano[4].seme;
	}

	for (i = 0; i < numGioc; i++) {
		analizzaMano (gioc, i);
	}
	contaFold = 0;
	contaVedi = 0;
	int piatto = 0;
	puntataPrec = 0;

	//punta vedi folda
	while (contaVedi < numGioc && contaFold < numGioc) {
		for (i = 0; i < numGioc; i++) {
			if (gioc[i].fold == FALSE && contaFold < numGioc && contaVedi < numGioc && gioc[i].cash > 0) {
				piatto += puntaVedi(gioc, i);
			}
		}
	}

	//controlla quanti hanno perso
	for (i = 0; i < numGioc; i++) {
		if (gioc[numGioc].cash <= 0) {
			contaKO++;
		}
	}

	/*trova vincitore*/
	int winner = vincitore(gioc, numGioc, piatto);

	return winner;
}
