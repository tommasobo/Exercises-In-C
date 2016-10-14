/* Ho usato una versione leggermente modificata della libreria usata per le lista per usare nomi più chiari e funzioni ottimizzate */

/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto CODA, implementato tramite allocazione statica
      (vettore contenente la sola parte informativa di ogni elemento della lista), in maniera dinamica con strutture collegate
      e sfruttando la libreria scritta sulle liste.

*/

#define MAX 50 // Numero massimo elementi della coda
#define EMPTYLIST -1 // Costante che viene usata per definire una coda vuota

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

struct StructCoda
{
    int ele[MAX];
    int last, first;
};
typedef struct StructCoda TipoCoda; // Definisco il tipo di dato "TipoCoda"

// Dichiaro i prototipi delle funzioni da utilizzare per la coda statica
void initialize(TipoCoda *coda);
int isEmpty(TipoCoda *coda);
int isFull(TipoCoda *coda);
void enQueue(TipoCoda *coda, int n);
void deQueue(TipoCoda *coda, int *n);
void printfirst(TipoCoda *coda);
