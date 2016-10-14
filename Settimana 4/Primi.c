#include <stdio.h>

int main ()
{
	int num, i;
	double sq;

	printf("Inserisci un numero positivo: ");
	scanf("%d", &num);

	while (num <= 0) {
		printf("Errore, devi inserire un numero maggiore di zero: ");
		scanf("%d", &num);
	}

	if (num % 2 == 0) {
		printf("\nIl numero %d non e\' primo", num);
		return 0;
	}
	else {
		for (i=3; i <= num; i+=2)
			if (num % i == 0) {
				printf("\nIl numero %d non e\' primo", num);
				return 0;
			}
			else {
				printf("\nNumero primo");
				return 0;
			}
	}

}


/*
int main()
{
    int nPrimi, n, k, i;

    p*/
