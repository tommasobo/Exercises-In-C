#define EMPTYLIST -1 // Definisco una costante nel caso la coda sia vuota

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

struct CodaD {
    int elem;
    struct CodaD *next;
};
typedef struct CodaD TipoCoda; // Definisco il tipo "TipoCoda"

// Dichiaro i prototipi delle funzioni che utilizzero per le code dinamiche
int isEmpty (TipoCoda **primo);
void enQueue(TipoCoda **primo, TipoCoda **ultimo, int n);
void deQueue(TipoCoda **primo);
void printListDin(TipoCoda **primo);
