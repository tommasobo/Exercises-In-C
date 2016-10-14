struct Cella {
    int valore;
    struct Cella *next;
};

#include <stdio.h>
#include <stdlib.h>

struct Cella* crea(int valore)
{
    struct Cella *nuovo;

    nuovo = (struct Cella*) malloc(sizeof(struct Cella));
    if (nuovo == NULL) {
        exit(EXIT_FAILURE);
    }
    nuovo->valore = valore;
    nuovo ->next = NULL;
    return nuovo;
}

void add(struct Cella **T, struct Cella *nuovo) {
    if (nuovo == NULL)
        return;
    nuovo->next = *T;
    *T = nuovo;
}

void stampa(struct Cella *T) {
    struct Cella *tmp;
    tmp = T;

    while (tmp !=NULL) {
        printf("%d ", tmp->valore);
        tmp = tmp->next;
    }
}

int elimina(struct Cella **T, int da_eliminare)
{
    struct Cella* tmp;
    struct Cella* prev;

    tmp = T;
    prev = NULL;

    while (tmp != NULL) {
        if (tmp->valore == da_eliminare) {
            if (prev == NULL)
                T = tmp->next;
            else
                prev->next = tmp->next;
            prev->next = tmp->next;
            tmp->next == NULL;
            free(tmp);
            return 1;
        }
        prev = tmp;
        tmp = tmp->next;
    }
    return 0;
}

struct Cella *cerca(struct Cella *T, int da_cercare) {
    struct Cella *tmp;

    tmp = T;

    while (tmp != NULL) {
        if (tmp->valore == da_cercare) {
            return tmp;
        }
        tmp = tmp->next;
    }
    return NULL;
}

int main()
{
    struct Cella *T = NULL;
    struct Cella *nuovo;

    add(&T, 10);

    return 0;
}
