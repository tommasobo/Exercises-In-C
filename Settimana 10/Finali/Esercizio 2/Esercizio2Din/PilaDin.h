/* Ho usato una versione leggermente modificata della libreria usata per le lista per usare nomi più chiari e funzioni ottimizzate */

/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto PILA, implementato tramite allocazione statica
      (vettore contenente la sola parte informativa di ogni elemento della lista), in maniera dinamica con strutture collegate
      e sfruttando la libreria scritta sulle liste.


*/

#define EMPTYLIST -1 // Costante per definire il caso in cui la lista sia vuota

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

struct PilaD {
    int elem;
    struct PilaD *next;
};
typedef struct PilaD TipoPilaDin; // Definisco il tipo TipoPilaDin

// Dichiaro i prototipi delle funzioni per le pile dinamiche
void initialize(TipoPilaDin **pTesta);
int isEmpty(TipoPilaDin **pTesta);
void push(TipoPilaDin **pTesta, int n);
void pop(TipoPilaDin **pTesta, int *value);
void printListDin(TipoPilaDin **pTesta);
