/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Testo esercizio: Predisporre una libreria di gestione del tipo di dato astratto LISTA, implementato sia tramite allocazione
      statica (vettore contenente la sola parte informativa di ogni elemento della lista) che in maniera dinamica con strutture
      collegate. Le funzioni che, come minimo, dovranno essere inserite nella libreria sono: inserisci in testa, inserisci in coda,
      inserisci dopo un certo elemento, cancella dalla testa, cancella dalla coda, cancella la prima occorrenza dell’elemento,
      cancella tutte le occorrenze dell’elemento, calcola la lunghezza della lista. Ove possibile, scrivere anche la versione
      ricorsiva di tali funzioni.
*/

#define EMPTYLIST -1 // Se la lista è vuota

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

// Definisco la mia struttura listD
struct listD {
    int elem;
    struct listD *next; // Puntatore alla struttura stessa
};

typedef struct listD LISTDIN_T;

// Prototipi funzioni per l'implementazione dinamica
int isEmpty(LISTDIN_T **pTesta);
void initializeDin(LISTDIN_T **pTesta);
void insertHead(LISTDIN_T **pTesta, int n);
void insertTail(LISTDIN_T **pTesta, int n);
void insertAfter(LISTDIN_T **pTesta, int n, int value);
void printListDin(LISTDIN_T **pTesta);
int lenList(LISTDIN_T **pTesta);
void cancelHead(LISTDIN_T **pTesta);
void cancelTail(LISTDIN_T **pTesta);
void cancelFirst(LISTDIN_T **pTesta, int n);
void cancelAll(LISTDIN_T **pTesta, int n);
void printListRec(LISTDIN_T **pTesta);
void numberRec(LISTDIN_T **pTesta, int n);
void resetListRec(LISTDIN_T **pTesta);
