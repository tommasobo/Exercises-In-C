#define MAX 50 // Numero massimo elementi della pila
#define EMPTYLIST -1

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
typedef struct StructCoda TipoCoda;
