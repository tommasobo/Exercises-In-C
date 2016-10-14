/*#include <stdio.h>

int main()
{
    int x,num,conta;

    printf("Inserisci un numero: ");
    scanf("%d",&num);

	printf("\nUtilizzo il costrutto for\n");
	if (num > 1) {  // Controllo che il numero inserito sia maggiore di 1
		printf("I divisori di %d sono: ",num);
		for (x=2; x<=num; x++) {
			if (num % x == 0) { // Controllo che il resto sia 0
				if (x == num) // Inserisco la virgola dopo il numero
					printf("%d.",x);
				else
					printf("%d, ",x); // Inserisco il punto dopo l'ultimo numero
					conta++;
			}
		}
	}
	else
		printf("Impossibile calcolare i divisiori di 0 o 1");

	printf("\n\nUtilizzo il costrutto while\n");

	x = 2;
	conta = 0;
	printf("I divisori di %d sono: ",num);
		while (x<=num) {
			if (num % x == 0) {
				if (x == num)
					printf("%d.",x);
				else {
					printf("%d, ",x);
				}
			}
			x++;
		}

	if (conta == 1) // Controllo se è un numero primo
		printf("\n\nIl numero che hai inserito e\' primo.\n");
	else
		printf("\n\nIl numero inserito non e\' primo.");
    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int numero, x;
    float num;

    printf("Inserisci un numero intero: ");
    scanf("%d", &numero);

    //controllo che il numero inseerito sia positivo
    while (numero < 0) {
        printf("Inserisci un numero positivo: ");
        scanf("%d", &numero);
    }

    /*utilizzo la variabile num pari alla metà del numero inserito perchè
    tutti i divisori di un numero, a parte sè stesso, sono compresi nella sua prima metà*/
    num = numero/2;

    if (numero == 0)
        printf("Impossibile");
    else
    printf("Il numero e\' divisibile per: \n");

    x = 1;

    while(x <= num) {
        if (numero%x == 0)    //se il resto tra numero e x è zero, x è un divisore di numero.
            printf("%d \n", x++);
        else
            x++; //incremento la x per il ciclo successivo
    }

    //stampo numero perchè è sempre un divisore di sè stesso
    printf("%d \n", numero);

    system("pause");
    return 0;
}
