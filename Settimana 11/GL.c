#include <stdio.h>
#include <stdlib.h>

typedef struct hangar {
    int spazio_occupato;
    PAereo lista_aerei;
} hangar;

typedef struct aereo {
    int spazio_occupato;
    struct aereo *next;
    struct aereo *prev;
} Aereo;
typedef Aereo *PAaereo;

int main()
{

    return 0;
}

int elimina(PCella *t, int da_eliminare)

{
    PCella tmp;

    tmp = *t;
    while (tmp != NULL) {
        if (tmp->valore == da_eliminare) {
            if (tmp->prev != NULL) {
                tmp->prev->next = tmp->next;
            }

            if (tmp->next != NULL)
                tmp->next->prev = tmp->prev;
            tmp->next = NULL;
            tmp->prev = NULL;
            free(tmp);
            return 1;
        }
        tmp = tmp->next;
    }

    return;
}

int elimina_tutto(PCella *t, int da_eliminare)

{
    PCella tmp, elimina, conta = 0;

    tmp = *t;
    while (tmp != NULL) {
        if (tmp->valore == da_eliminare) {
            elimina = tmp;
            tmp = tmp->next
            if (elimina->prev != NULL) {
                elimina->prev->next = elimina->next;
            }

            if (elimina->next != NULL)
                elimina->next->prev = elimina->prev;
            elimina->next = NULL;
            elimina->prev = NULL;
            free(elimina);
            conta++;
            return conta;
        } else
            tmp = tmp->next;
    }

    return;
}

void inserisci(PHangar *h, PAereo a)
{
    PHangar tmp;

    tmp = trovaHangar(*h, a->dimensione);
    if (tmp == NULL)
        tmp = creaInserisciHangar(h);
    aggiungiAereoAdHangar(tmp,a);
}

PHangar trovaHangar(PHangar h, int dimensione)
{
    while (h != NULL) {
        if (DISPONIBILITA - h->spazio_occupato >= dimensione) {
            return h;
        }
        h = h->next;
    }
    return NULL;
}

PHangar creaInserisciHangar(PHANGAR *h)
{
    PHangar nuovo = (PHangar) malloc(sizeof(Hangar));
    if (nuovo == NULL)
        exit(1);
    nuovo->spazio_occupato = 0;
    nuovo->next = NULL;
    nuovo->prev = NULL;
    nuovo->lista_aerei = NULL;

    nuovo->next = *h;
    if (*h != NULL) {
        (*h)->prev = nuovo;
    }
    *h = nuovo;
    return nuovo;
}

void aggiungiAereoAdHangar (PHangar h, Aereo a)
{
    a->next = h->lista_aerei;
    if (h->lista_aerei != NULL) {
            h->lista_aerei->prev = a;
    }
    h->lista_aerei = a;
}

void svuota(PHangar *h)
{
    while(*h != NULL) {
        tmp = *h;
        *h = (*h)->next;
        while (tmp->lista_aerei != NULL) {
            elimina = tmp->lista_aerei;
            tmp->lista_aerei = tmp->lista_aerei->next;

            if (elimina->next != NULL)
                elimina->next->prev = NULL;
            elimina->prev = NULL;
            free(elimina);
        }
        if (tmp->next != NULL)
            tmp->next->prev = NULL;
        tmp->next = NULL;
        free(tmp);
    }
}
