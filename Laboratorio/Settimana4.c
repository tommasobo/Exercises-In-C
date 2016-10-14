#include <stdio.h>

int main() {
	int n,i;
	
	do {
		printf("Inserisci un numero intero positivo maggiore di uno: ");
		scanf("%d", &n);
	} while (n <= 1);
	
	for (i=2; i<n; i++)
		if (n%i == 0) {
			printf("Il numero %d non e\' primo",n);
			break;
		}
	if (i == n)
		printf("Il numero e\' primo");
		
	return 0;
}
