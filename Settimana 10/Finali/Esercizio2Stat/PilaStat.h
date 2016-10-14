/* Ho usato una versione leggermente modificata della libreria usata per le lista per usare nomi più chiari e funzioni ottimizzate */

/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto PILA, implementato tramite allocazione statica
      (vettore contenente la sola parte informativa di ogni elemento della lista), in maniera dinamica con strutture collegate
      e sfruttando la libreria scritta sulle liste.


*/

#define MAX 50 // Numero massimo elementi della pila
#define EMPTYLIST -1 // Se la lista è vuota

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

// Definisco una struttura
struct StructPila {
    int ele[MAX];
    int last;
};
typedef struct StructPila TipoPila;

// Dichiaro i prototipi dele funzioni
int isFull(TipoPila *pila);
int isVoid(TipoPila *pila);
void initialize(TipoPila *pila);
void push(TipoPila *pila, int ele);
void pop(TipoPila *pila, int *value);
void printList(TipoPila *pila);
