#include <stdio.h>
#include <stdlib.h>
#define max 31

int main ()
{
    //dichiaro due vettori, ciascuono per 31 giorni (un mese) per ognuno dei colleghi
    int vettore1[max], vettore2[max], giorni = 0, x, y, i, valore;

    //inizializzo il primo vettore a 0
    for (x = 0; x < 31; x++)
        vettore1[x] = 0;

    //faccio inserire il numero di giorni disponibili a un incontro
    printf("Quanti giorni disponibili ha il primo collega?: ");
    scanf("%d", &giorni);

    //controllo che il numero inserito sia verosimilmente un giorno del mese
    while (giorni > 31 || giorni < 0) {
        printf("Primo collega reinserisci un numero di giorni possibile (compreso tra 0 e 31)");
        scanf("%d", &giorni);
    }

    //se il primo collega non ha giorni disponibili faccio uscire direttamente il ciclo
    if (giorni == 0) {
        printf("I due colleghi non possono incontrarsi questo mese perche\' il primo collega e\' sempre impegnato \n");
        system ("pause");
        return 0;
    }

    //se ci sono giorni disponibili li faccio inserire tramite un while
    x = 0;
    valore = 0;
    while (x < giorni) {
        printf("Inserisci il primo giorno disponibile: ");
        scanf("%d", &valore);

        //controllo che il valore non sia minore o uguale a 0 o maggiore di 31
        while (valore <= 0 || valore > 31) {
            printf("Inserisci un numero di giorni possibile (compreso tra 0 e 31): ");
            scanf("%d", &valore);
        }

        //controllo che il giorno non sia già stato inserito
        while (vettore1[valore-1] == 1) {
            printf("Il giorno appena inserito era già stato dichiarato disponibile, inserirne uno differente: ");
            scanf("%d", &valore);
        }

        vettore1[valore-1] = 1;     //cambio il valore nella cella a seconda del giorno inserito dall'utente
        x++;    //x tiene il conto dei giorni inseriti

    }

    // ripeto la stessa cosa per il secondo collega
    for (y = 0; y < 31; y++)
        vettore2[y] = 0;

    printf("Quanti giorni disponibili ha il secondo collega?: ");
    scanf("%d", &giorni);

    while (giorni > 31 || giorni < 0) {
        printf("Secondo collega reinserisci un numero di giorni possibile (compreso tra 0 e 31)");
        scanf("%d", &giorni);
    }

    if (giorni == 0) {
        printf("I due colleghi non possono incontrarsi questo mese perche\' il secondo collega e\' sempre impegnato");
        system ("pause");
        return 0;
    }

    y = 0;
    valore = 0;
    while (y < giorni) {
        printf("Inserisci il primo giorno disponibile: ");
        scanf("%d", &valore);

        //controllo che il valore non sia minore o uguale a 0 o maggiore di 31
        while (valore <= 0 || valore > 31) {
            printf("Inserisci un numero di giorni possibile (compreso tra 0 e 31): ");
            scanf("%d", &valore);
        }

        //controllo che il giorno non sia già stato inserito
        while (vettore2[valore-1] == 1) {
            printf("Il giorno appena inserito era già stato dichiarato disponibile, inserirne uno differente: ");
            scanf("%d", &valore);
        }

        vettore2[valore-1] = 1;
        y++;

    }

    //controllo che entrambi i colleghi abbiano lo stesso giorno disponibile scorrendo il contatore parallelamente
    for (i = 0; i <= 31; i++) {
        if (vettore1[i] == 1 && vettore2[i] == 1) {
            printf("Il giorno %d e\' disponibile a entrambi \n", i+1);
        }
    }

    system("pause");
    return 0;

}/*#include <stdio.h>
#include <stdlib.h>
#define N 6
#define R 1

int main()
{
    int M[N][N];
    int i, j, a, b, x;

    x = 0;

    srand(10);
    for (i=0; i < N; i++)
        for (j=0; j < N; j++)
            M[i][j] = rand() % 2;

    printf("Matrice iniziale: \n");
    for (i=0; i < N; i++) {
        for (j=0; j < N; j++)
            printf("%d ", M[i][j]);
        printf("\n");
    }

    printf("\nMatrice toroidale :\n");
    for (i=0; i < N; i++) {
        for (j=0; j < N; j++) {
            x = 0;
            for (a = -R; a <= R; a++)
                for (b = -R; b <= R; b++)
                   // if (!(i+a < 0 || j+b < 0))
                    x += M[(i+a+N)%N][(j+b+N)%N]; // +N permette di trattare i negativi
                printf("%d ", x);
        }
        printf("\n");
    }

    return 0;

}
*/
