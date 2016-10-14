/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h> /* Includo la libreria standartd input/output per utilizzare le funzione printf e puts */
#include <stdlib.h> /* Includo la libreria stdlib per poter utilizzare la funzione system */

int main() /* Definisce la funzione main che non si aspetta alcun argomento dalla funzione chiamante e che restituirà un numero intero*/
{ /*Le istruzioni di main sono racchiuse tra parentesi graffe */
	printf("Cantanti visualizzati uno per linea: \n"); /* La stessa cosa poteva essere fatta mettendo tutti i nomi dei cantanti all'interno di un unico printf separati da un "\n" per andare a capo */
	printf("* Kate Perry \n");
	printf("* Linkin Park \n");
	printf("* Imagine Dragons \n");
	printf("* Lana Del Rey \n");
	printf("* Calvin Harris \n");
	printf("* Enya \n");
	printf("* Coldplay \n");
	printf("* Luciano Pavarotti \n");
	printf("* Ellie Goulding \n");
	printf("* Lisa Gerrard \n\n");
		
	printf("Cantanti visualizzati due per linea: \n"); /* Questa volta stampo due cantanti per ogni linea*/
	printf("* Kate Perry e Linkin Park \n");
	printf("* Imagine Dragons e Lana Del Rey \n");
	printf("* Calvin Harris e Enya \n");
	printf("* Coldplay e Luciano Pavarotti \n");
	printf("* Ellie Goulding e Lisa Gerrard \n\n");
		
	printf("Cantanti visualizzati con tabulazione: \n"); /* Uso la sequenza di escape \t per lasciare uno spazio di tabulazione prima del nome dei cantanti) */
	printf("\t* Kate Perry \n");
	printf("\t* Linkin Park \n");
	printf("\t* Imagine Dragons \n");
	printf("\t* Lana Del Rey \n");
	printf("\t* Calvin Harris \n");
	printf("\t* Enya \n");
	printf("\t* Coldplay \n");
	printf("\t* Luciano Pavarotti \n");
	printf("\t* Ellie Goulding \n");
	printf("\t* Lisa Gerrard \n\n");
	
	puts("Cantanti visualizzati uno per linea utilizzando \"puts\":"); /*Questa volta utilizzo la funzione puts al posto di printf che manda a capo automaticamente il cursore dopo aver stampato la stringa */
	puts("* Linkin Park");
	puts("* Imagine Dragons");
	puts("* Lana Del Rey");
	puts("* Calvin Harris");
	puts("* Enya");
	puts("* Coldplay");
	puts("* Luciano Pavarotti");
	puts("* Ellie Goulding");
	puts("* Lisa Gerrard \n");
	
	puts("Cantanti visualizzati due per linea utilizzando \"puts\":"); 
	puts("* Kate Perry e Linkin Park");
	puts("* Imagine Dragons e Lana Del Rey");
	puts("* Calvin Harris e Enya");
	puts("* Coldplay e Luciano Pavarotti");
	puts("* Ellie Goulding e Lisa Gerrard \n");
	
	puts("Cantanti visualizzati con tabulazione utilizzando \"puts\":"); 
	puts("\t* Kate Perry");
	puts("\t* Linkin Park");
	puts("\t* Imagine Dragons");
	puts("\t* Lana Del Rey");
	puts("\t* Calvin Harris");
	puts("\t* Enya");
	puts("\t* Coldplay");
	puts("\t* Luciano Pavarotti");
	puts("\t* Ellie Goulding");
	puts("\t* Lisa Gerrard");
	
	system("pause"); /* La funzione in questione può essere utilizzata solo con sistemi Windows ed inoltre con alcuni IDE (come CodeBLocks e alcuni versioni di Dev C++) è superflua in quanto la console rimane aperta anche dopo l'esecuzione del programma */
	
	return 0; /* Indica che il programma, quando termina normalmente, restituisce il valore 0 al sistema operativo */
}
