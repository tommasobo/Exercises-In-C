/*#include <stdio.h>
#define N_ELE 100


int main () {
	
	int resto[N_ELE], valore, i, k;
	
	printf("Inserisci un valore da convertire in binario: ");
	scanf("%d", &valore);
	
	for (i=0; valore >= 1; i++) {
		resto[i] = (valore % 2);
		valore = valore / 2;
	}
	
	i  = i - 1; // Diminuisco di uno il valore di i per farlo corrispondere al numero dell'ultimo elemento usato nell array
	
	for (k = i; k >= 0; k--) {
		printf("%d",resto[k]);
	}
	
	
	return 0;
	
}
*/#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int valore, vettore[1000], i = 0, j, k, l;

    printf("Inserisci un valore intero positivo diverso da zero: ");
    scanf("%d", &valore);

    //controllo che il valore sia positivo
    while (valore <= 0) {
        printf("Inserisci un valore valido: ");
        scanf("%d", &valore);
    }

    //converto il valore decimale inserito in binario dividendolo per 2 fino ad ottenere uno e memorizzando i resti in un array
    while (valore >= 1) { 
        vettore[i] = valore % 2 ;
        valore = valore/2;
        i++;
    }

    //inverto il vettore e lo rimemorizzo per ottenere il numero binario corretto
    j = i-1;
    k = 0;
    while (k<i/2) {
        l = vettore[j];
        vettore[j] = vettore[k];
        vettore[k] = l;
        j--;
        k++;
    }

    //stampo il nuovo vettore
    printf("Il numero inserito in codice binario equivale a: ");
    k = 0;
    while (k < i) {
    printf("%d", vettore[k]);
    k++;
    }

    printf("\n");

    system ("pause");
    return 0;

}
