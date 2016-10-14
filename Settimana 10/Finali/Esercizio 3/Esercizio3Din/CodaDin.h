/* Ho usato una versione leggermente modificata della libreria usata per le lista per usare nomi più chiari e funzioni ottimizzate */

/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto CODA, implementato tramite allocazione statica
      (vettore contenente la sola parte informativa di ogni elemento della lista), in maniera dinamica con strutture collegate
      e sfruttando la libreria scritta sulle liste.

*/

#define EMPTYLIST -1 // Definisco una costante nel caso la coda sia vuota

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

struct s_nodocoda { //Definisco la struttura s_nodocoda
    int elem;
    struct s_nodocoda *next;
};
typedef struct {
    struct s_nodocoda *first;
    struct s_nodocoda *last;
} TipoCoda; // Definisco il tipo "TipoCoda"

// Dichiaro i prototipi delle funzioni che utilizzerò con le code dinamiche
void initialize(TipoCoda*);
void resetCoda(TipoCoda*);
int isEmpty(TipoCoda);
int first(TipoCoda, int *n);
int deQueue(TipoCoda*, int *n);
int enQueue(TipoCoda*, int n);

