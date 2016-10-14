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

#define N 50 // Numero massimo elementi della lista
#define EMPTYLIST -1 // Se la lista è vuota
#define UNDEFINED -2 // Errore generico

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

// Definisco il tipo LISTSTAT_T
typedef struct {
    int ele[N];
    int last;
} LISTSTAT_T;

// Prototipi funzioni per l'implementazione statica
int isFull(LISTSTAT_T *listStat);
void initialize(LISTSTAT_T *listStat);
void printList(LISTSTAT_T *listStat);
void insert(LISTSTAT_T *listStat, int pos, int ele);
void printList(LISTSTAT_T *listStat);
int find(LISTSTAT_T *listStat, int value);
void del(LISTSTAT_T *listStat, int pos);
void delAll(LISTSTAT_T *listStat, int value);
