#include <stdio.h>
#include <stdlib.h>
#define MAX 2

int main()
{
    int i;
    struct calendario_data { // DICHIARO LA STRUTTURA
        int giorno;
        int mese;
        int anno;
    } data[MAX];

    for (i = 0; i < MAX; i++) {
        printf("Inserisci un giorno: ");
        scanf("%d", &data[i].giorno);
        // Controllo il giorno
        while (data[i].giorno < 1 || data[i].giorno > 31) {
            printf("Giorno non valido, inserire nuovo giorno: ");
            scanf("%d", &data[i].giorno);
        }

        printf("Inserisci un mese (in numero): ");
        scanf("%d", &data[i].mese);
        // Controllo il mese
        while (data[i].mese < 1 || data[i].mese > 12) {
            printf("Mese non valido, inserirne uno nuovo: ");
            scanf("%d", &data[i].mese);
        }

        printf("Inserisci l\'anno: ");
        scanf("%d", &data[i].anno);

        // Controllo l'anno
        while (data[i].anno <= 0) {
            printf("Anno non valido, inserirne uno valido: ");
            scanf("%d", &data[i].anno);
        }

        printf("\n\n");
    }


    if (data[0].anno > data[1].anno)
        printf("Il primo giorno e\': %d - %d - %d", data[1].giorno, data[1].mese, data[1].anno);
    else if (data[0].anno < data[1].anno)
        printf("Il primo giorno e\': %d - %d - %d", data[0].giorno, data[0].mese, data[0].anno);
    else {
        if (data[0].mese > data[1].mese)
            printf("Il primo giorno e\': %d - %d - %d", data[1].giorno, data[1].mese, data[1].anno);
        else if (data[0].mese < data[1].mese)
            printf("Il primo giorno e\': %d - %d - %d", data[0].giorno, data[0].mese, data[0].anno);
        else {
            if (data[0].giorno > data[1].giorno)
                printf("Il primo giorno e\': %d - %d - %d", data[1].giorno, data[1].mese, data[1].anno);
            else if (data[0].giorno < data[1].giorno)
                printf("Il primo giorno e\': %d - %d - %d", data[0].giorno, data[0].mese, data[0].anno);
        }
    }

    return 0;
}
