#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    int add1 = 10, add2 = 3, risultato;
    int sum(int,int);

    risultato = sum(add1, add2);
    printf("Somma: %d", risultato);

    return 0;
}

int sum(int a, int b)
{
    int somma;

    somma = a + b;

    return somma;
}
*/

/*
 * Enrico Salvucci
 *
 * Esercizio 1
 * Settimana 8
 *
 * Consegna: Si scriva una funzione in C, denominata cerca, che ricerchi la presenza di un elemento in un vettore di interi.
 * 			 La funzione riceve in ingresso tre parametri:
 * 				1. un vettore di interi vettore[] nel quale ricercare il valore;
 * 				2. un valore intero dimensione che indica quanti elementi contiene il vettore;
 * 				3. il valore intero elem che deve essere ricercato.
 * 			 La funzione deve restituire un valore intero, ed in particolare:
 * 					_ se il valore elem è presente nel vettore, allora la funzione restituisce l’indice della posizione alla quale si trova tale valore;
 * 			 		_ se il valore elem è presente più volte, si restituisca l’indice della prima occorrenza;
 * 					_ se il valore elem non è presente nel vettore, si restituisca -1.
 * 			 Si modifichi la funzione cerca definendo la funzione cerca_vettore_ordinato che faccia le stesse cose descritte in precedenza ma sul vettore ordinato.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int Ordinamento();

int main()
{
    int **vettore/* Puntatore di puntatori */, dimensione, k, i, j, h ;
    srand((int) time(NULL));

    printf("Inserire quanti vettori dinamici si vogliono creare : ");
    fflush(stdin);
    k = scanf("%d",&dimensione);

    while( k == 0 )
    {
           printf("\n\nErrore di Input!Reinserire quanti vettori dinamici si vogliono creare : ");
           fflush(stdin);
           k = scanf("%d", &dimensione);

    }

    vettore = (int**) malloc ( dimensione * sizeof(int) ); /* Vettore di puntatori */

    for( k = 0 ; k < dimensione ; k++ )
    {
         vettore[k] = (int*) malloc (( k+2 ) * sizeof(int) ); /* Creo un vettore da ogni puntatore di vettori */

    }

    printf("\nI Valori Random memorizzati nei vettori dinamici creati sono :\n");

    for ( k = 0 ; k < dimensione ; k++ )
    {
        puts("");

        for( i = 0 ; i < (k + 2) ; i++ )
        {
             vettore[k][i] =  -100 + (rand()% 200);
             printf("%d  ", vettore[k][i]);
        }
    }

    puts("\n");
    system("pause");
    system("cls");
    fflush(stdin);

    printf("I valori Random memorizzati nei vettori disposti in ordine crescente sono : \n");

    for ( k = 0 ; k < dimensione ; k++ )
    {
        puts("");

        for( i = 0 ; i < ( k + 2 ) ; i++ )
        {
             qsort(vettore[k], dimensione, sizeof(int), Ordinamento );
             printf("%d  ", vettore[k][i]);

        }
    }

    int massimo = 0;

    for ( k = 0 ; k < dimensione ; k++ )
    {
        for(i = 0 ; i < ( k + 2 ) ; i++ )
        {
              if( vettore[k][i] >= massimo )
              {
                  massimo = vettore[k][i];

              }
        }
    }

    printf("\n\nIl numero intero maggiore contenuto nei vettori e' %d ", massimo);

    int ripetuto = 0,
    contatore = 0 ;

    for ( k = 0 ; k < dimensione ; k++ )
    {
        for( i = 0 ; i < (k + 2) ; i++ )
        {
             ripetuto = vettore[k][i];

             for ( j = 0 ; j < dimensione ; j++)
             {
                 for ( h = 0 ; j < ( j + 2 ) ; h++)
                 {
                     if( vettore[j][h] == ripetuto )
                     {
                         contatore++;

                     }
                 }
             }
        }
    }

    printf("Il numero presente piu' volte nella matrice e' %d ripetuto %d volte",ripetuto,contatore);

    puts("\n");
    system("pause");
    return 0;

}

int Ordinamento ( const void *P, const void *S )
{
    int *a, *b ;

    a = (int*) P ;
    b = (int*) S ;

    if ( *a == *b )
    {
         return 0;

    }

    if ( *a < *b )
    {
         return -1;

    }

    if ( *a > *b )
    {
         return 1;

    }

}
