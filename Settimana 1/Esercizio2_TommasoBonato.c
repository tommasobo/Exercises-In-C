/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	/*In questo programma verranno utilizzati i caratteri di escape che permettono di utilizzare comandi di formattazione particolare */
	
	printf("Utilizzo la sequenza di escape che mi permette di andare a capo \n\n");
	printf("\tUtilizzo la sequenza di escape che permette di eseguire la tabulazione \n\n");
	printf("Utilizzo la sequenza di escape che mi permette di visualizzare il backslash (\\) \n\n");
	printf("Utilizzo la sequenza di escape che mi permette di visualizzare gli apici (\') \n\n");
	printf("Utilizzo la sequenza di escape che mi permette di visualizzare i doppi apici (\") \n\n");
	printf("Utilizzo la sequenza di escape che mi permette di visualizzare il punto interrogativo (\?) \n\n");
	printf("Utilizzo la sequenza di escape che mi permette di riprodurre un segnale acustico \a \n\n");
	printf("Utilizzo la sequenza di escape che mi permette di cancellare un  \bcarattere \n\n");
	
	/* Esistono altre funzioni di escape come \v e\f ma non sembrano funzionare correttamente sui computer più recenti */
	
	system("pause"); /* Compatibile solo con Windows */
	
	return 0;
}
