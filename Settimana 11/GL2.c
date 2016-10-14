#include <stdio.h>

typedef struct Cella {
    int valore;

    struct Cella *next;
} Cella;

typedef Cella *PCella;

int main() {
    PCella testa= NULL;

    return 0;
}

void stampa(PCella t)
{
    if (t == NULL)
        return;

    PCella tmp = t;

    do {
        printf("%d ", tmp->valore);
        tmp = tmp->next;
    } while (tmp != t);
}

void inserisci(PCella t, int ele)
{
    PCella nuovo, ultimo;
    ultimo = *t;
    nuovo = (PCella) malloc(sizeof(Cella));
    if (nuovo == NULL) {
        printf("Errore!");
        exit(1);
    }
    nuovo->valore = ele;

    if (*t == NULL) {
        *t = nuovo;
        nuovo->next = nuovo;
        return;
    } else {
    while (ultimo->next= *t) {
        ultimo = ultimo->next;
    }
        nuovo->next = *t;
        utimo->next = nuovo;
        *t = nuovo;
    }

}

void inserisci(PCella *t, PCella n)
{


    return;
}
