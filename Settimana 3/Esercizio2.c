/* 
 * Enrico Salvucci
 *
 * Esercizio 15
 * Settimana 2
 * 
 * Consegna: Scrivere un programma C che, dato il valore dello stipendio lordo, calcoli lo stipendio netto mensile considerando una sola tassazione pari al 20% per stipendi lordi compresi
 * 			fra 10.001 euro e 30.000 euro, pari al 30% oltre ai 30.000 euro e esentasse per gli stipendi lordi inferiori a 10.000 euro.
 *   
 */
 
#include <stdio.h>

int main()
{

	int stipendio_lordo, stipendio_netto_20, stipendio_netto_30, tassazione_20, tassazione_30;
	
	// stampo il valore dello stipendio lordo
	printf("Inserisci il valore dello stipendio lordo\n");
	scanf("%d", &stipendio_lordo);

	tassazione_20 = stipendio_lordo * 20 /100;
	tassazione_30 = stipendio_lordo * 30 /100;
	stipendio_netto_20 = stipendio_lordo - tassazione_20;
	stipendio_netto_30 = stipendio_lordo - tassazione_30;

// se lo stipendio è compreso tra i 10.001 euro e 30.000 la tassazione è del 20%
if ( stipendio_lordo >= 10000 && stipendio_lordo < 30000 )
	{	
		printf("La tassazione è del 20%%\nLo stipendio netto è %d\n", stipendio_netto_20);
	}

// se lo stipendio è > 30.000 euro la tassazione è del 30%
if ( stipendio_lordo > 30000 )
	{
		printf("La tassazione è del 30%%\nLo stipendio netto è %d\n", stipendio_netto_30);
	}
// se lo stipendio è < 10.000 euro non c'è tassazione
if ( stipendio_lordo < 10000 ) 

	printf("Lo stipendio netto è %d e non vi è stata applicata alcuna tassazione\n", stipendio_lordo);
}
