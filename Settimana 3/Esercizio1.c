#include <stdio.h>

int main()
{
    int col,row,ic,ir;

    printf("Inserisci il numero di righe: ");
    scanf("%d",&row);
    printf("Inserisci il numero di colonne: ");
    scanf("%d",&col);
    printf("\n");

    printf("X\t");
    for (ic=0; ic<col; ic++){
                printf("%d\t",ic);
        }
        printf("\n");

    for (ir=0; ir<row; ir++) {  // Risolvo l'esercizio con il ciclo for
            printf("%d\t",ir);
        for (ic=0; ic<col; ic++){
                printf("%d\t",ic*ir);
        }
        printf("\n");
    }


    printf("\n\n");
    ir = 0;
    printf("X\t");
    for (ic=0; ic<col; ic++){
                printf("%d\t",ic);
        }
        printf("\n");
    while (row>ir)  // Risolvo l'esercizio con il ciclo while
    {
        ic = 0;
         printf("%d\t",ir);

        while (col>ic)
        {
            printf("%d\t",ic*ir);
            ic++;
        }
        printf("\n");
        ir++;
    }

    return 0;
}
