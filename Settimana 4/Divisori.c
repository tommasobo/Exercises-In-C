#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{

    int num, x;

    printf("Inserisci un numero positivo intero: ");
    scanf("%d", &num);

    while (num <= 0) {
        printf("Errore, devi inserire un numero maggiore di zero: ");
        scanf("%d", &num);
    }

	if (num == 1)
        printf("Il divisore di %d e\': ",num);
    else
        printf("I divisori di %d sono: ",num);

	for (x=1; x <= num/2; x++) {
		if (num % x == 0) { // Controllo che il resto sia 0
            printf("%d, ",x);
		}
	}
	printf("%d. ",num); //

	printf("\n\n");
	system("pause");

	return 0;

}
