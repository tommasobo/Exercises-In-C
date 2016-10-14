#include <stdio.h>


int main() {

	int array[4], num;

	printf("Inserisci un numero intero maggiore di mille: ");
	scanf("%d", &num);

	while (num < 1000) {
		printf("Errore, devi inserire un numero maggiore di 1000: ");
		scanf("%d", &num);
	}

	array[0] = (num / 1000);
	array[1] = ((num % 1000) / 100);
	array[2] = (((num % 1000) % 100) / 10);
	array[3] = (((num % 1000) % 100) % 10);

	printf("\nMigliaia: %d\nCentinaia: %d\nDecine: %d\nUnita: %d\n", array[0], array[1], array[2], array[3]);

	getchar();

	return 0;
}
