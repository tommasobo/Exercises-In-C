/*Terza settimana
Esercizio 4: Scrivere un programma C che, dato il valore dello stipendio lordo, 
calcoli lo stipendio netto mensile considerando una sola tassazione 
pari al 20% per stipendi lordi compresi fra 10.001 euro e 30.000 euro, 
pari al 30% oltre ai 30.000 euro e 
esentasse per gli stipendi lordi inferiori a 10.000 euro.
    Eleonora Guidi 
    Mat:0000691977 */

/*modifiche apportate:
    - divisione in funzioni
*/
    
#include <stdio.h>
#include <stdlib.h>

float controllo ();

int main ()
{
    //scelgo valori con virgola mobile perchè lo stipendio non è necessariamente intero (situazione improbabile)
    float lordo, netto1, netto2;

    lordo = controllo(); 
    
    //inizio delle condizioni richieste dall'esercizio
    
    if (lordo <= 10000 || lordo > 0)    
        printf("Il tuo stipendio netto mensile e\': %.2f \n", lordo / 12);
        
    else if (lordo <= 30000 || lordo > 10000) {
        netto1 = lordo - (lordo - 10000) * 0.2;
        printf("Il tuo stipendio netto mensile e\': %.2f \n", netto1 / 12);
    }    
    
    else {
        netto2 = lordo - (lordo - 10000) * 0.3;
        printf("Il tuo stipendio netto mensile e\': %.2f \n", netto2 / 12);
    }    
    
    system ("pause");
    return 0;
} 

float controllo () {
    int n;
    printf("Inserisci il valore del tuo stipendio lordo annuale: \n");
    scanf ("%d", &n);
    while (n <= 0) {
        printf("Inserisci un valore positivo: \n");
        scanf("%d", &n); 
    }
    return n;
}   
