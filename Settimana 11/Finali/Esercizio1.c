/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Questo programma gestisce un archivio studenti
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define MAX 101 // Numero massimo di caratteri (100 + 1 per il terminatore di stringa) per i campi nome..
#define N_ESAMI 6 // Numero esami con cui ho deciso di lavorare

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

typedef struct StudentS{
    int code;
    char name[MAX];
    char surname[MAX];
    char address[MAX];
    int voti[N_ESAMI];
    int esami [N_ESAMI];
    struct StudentS *next;
} TypeStudent;

typedef struct YearS {
    int year;
    int code; // 0 se c'è il numero programmato, 1 se non c'è
    int maxStudents; // Se c'è il numero programmato, questa variabile indica il numero massimo di studenti
    int nStudents; // Numero di studenti iscritti
    TypeStudent *student;
    struct YearS *next;
} TypeYear;

// Prototipi delle funzioni
void insertYear (TypeYear **head);
void insertStudent (TypeYear *head);
void cancel(TypeYear *head);
void printList(TypeYear *head);
int checkValue(int value, int check, int min, int max);
void clearBuffer();
int isEmpty(TypeYear *head);
void todo(TypeYear *head);
void searchHighest (TypeYear *head);
void searchStud(TypeYear *head);
void freeMemory(TypeYear *head);

int main()
{
    int MenuChoice, check;
    TypeYear *head = NULL; // Inizializzo la testa a NULL

    while (MenuChoice != 9) {
        system(CLEAR);
        printf("\t\t ---- GESTIONE ANNI ACCADEMICI ----\n\n");
        printf("1 - Inserisci un nuovo anno accademico\n");
        printf("2 - Inserisci un nuovo studente\n");
        printf("3 - Visualizza l\'archivio\n");
        printf("4 - Elimina uno studente\n");
        printf("5 - Esci dal programma\n\n");
        printf("Scegli un opzione dal menu: ");
        check = scanf("%d", &MenuChoice);
        MenuChoice = checkValue(MenuChoice, check, 1, 5);

        switch(MenuChoice) {
            case 1 :
                insertYear(&head);
                break;
            case 2 :
                insertStudent(head);
                break;
            case 3 :
                printList(head);
                break;
            case 4 :
                cancel(head);
                break;
            case 5 :
                freeMemory(head); // Libero la memoria
                exit(EXIT_SUCCESS);
                break;
            default : // Non dovrebbe verificarsi mai grazie al controllo sull'input, ma lo implemento per sicurezza
                printf("Errore, scelta non valida");
                freeMemory(head);
                exit(EXIT_FAILURE);
        }

    }

    freeMemory(head); // Libero la memoria

    return 0;
}

/*
 * Funzione checkValue
 * --------------------
 * Controlla che il numero inserito dall'utente sia valido.
 * Prende in ingresso quattro valori: il numero su cui eseguire il controllo, il valore di ritorno della scanf e i due estremi (inferiore e superiore) su cui fare il controllo
 * Restituisce il valore (un intero) dopo che il controllo è risultato valido
*/
int checkValue(int value, int check, int min, int max)
{

    clearBuffer();
    while (value < min || value > max || check != 1) {
        printf("Errore, devi inserire un valore valido compreso tra %d e %d: ", min, max);
        check = scanf("%d", &value);
        clearBuffer();
    }

    return value;
}

void clearBuffer() // Definisco una funzione per pulire il buffer da tastiera che è completamente portabile
{
    char ch;
    do
    {
        ch = getchar();
    } while (('\n' != ch) && (EOF != ch));
}

int isEmpty(TypeYear *head) // Controllo se la lista principale è vuota. In caso affermativo restituisco 1
{
    if (head == NULL)
        return 1;
    return 0;
}

void freeMemory(TypeYear *head) // Questa funzione libera la memoria allocata dinamicamente
{
    TypeYear *temp, *prev;
    TypeStudent *tempS, *prevS;

    temp = head;

    while(temp != NULL) { // Scorro la lista principale
        tempS = temp->student;
        while(tempS != NULL) { // Scorro la lista secondaria
            prevS = tempS;
            tempS = tempS->next;
            free(prevS); // Libero la memoria
        }
        prev = temp;
        temp = temp->next;
        free(prev);
    }
}

void insertYear (TypeYear **head) // Questa funzione inserisce un nuovo anno in modo ordinato cronologicamente
{
    TypeYear *newYear, *temp, *prev;
    int check;

    temp = *head;
    system(CLEAR);


    newYear = (TypeYear*) malloc(sizeof(TypeYear)); // Alloco lo spazio per un anno e controllo la malloc
    if (newYear == NULL) {
        printf("Errore durante l\'allocazione dinamica della memoria");
        freeMemory(*head);
        exit(EXIT_FAILURE);
    }

    printf("\t\t\t ---- INSERISCI UN ANNO ACCADEMICO ----\n\n");
    printf("Inserisci l\'anno: ");
    check = scanf("%d", &newYear->year);
    newYear->year = checkValue(newYear->year, check, 1088, INT_MAX);

    printf("Inserisci 0 se e\' presente il numero programmato o 1 se non e\' presente: ");
    check = scanf("%d", &newYear->code);
    newYear->code = checkValue(newYear->code, check, 0, 1);

    if (newYear->code == 0) { // Se è a numero programmato richiedo il numero massimo di studenti
        printf("Inserisci il numero massimo di studenti: ");
        check = scanf("%d", &newYear->maxStudents);
        newYear->maxStudents = checkValue(newYear->maxStudents, check, 0, 2000);
    }

    prev = NULL;
    if (isEmpty(*head)) { // Se la lista è vuota modifico la testa
        newYear->next = *head;
        *head = newYear;
    } else {
        while (temp != NULL && newYear->year > temp->year) { // Scorro la lista fino alla fine o fino a quando incontro un anno maggiore
            prev = temp;
            temp = temp->next;
        }
        if (temp != NULL && newYear->year == temp->year) { // Controllo che l'anno non sia già presente
            printf("Errore, anno %d gia\' presente", temp->year);
            printf("\nPremere invio per continuare...");
            free(newYear);
            getchar();
            return;
        }
        if (newYear->year < (*head)->year) { // Se l'elemento da inserire è in testa
            newYear->next = *head;
            *head = newYear;

        } else { // Altrimenti se l'inserimento sta avvenendo in mezzo alla lista
            newYear->next = temp;
            prev->next = newYear;
        }
    }

    newYear->nStudents = 0; // Inizializzo il numero di studenti a 0
    newYear->student = NULL; // Inizializzo a NULL il puntatori a student

    return;
}

void insertStudent (TypeYear *head) // Questa funzione inserisce uno studente in testa
{
    TypeYear *temp, *tempY;
    TypeStudent *newStudent, *tempS;
    int check, length, year, found = 0, i;
    char nomiesami[][50] = {"Programmazione", "Inglese", "Analisi", "Algebra", "Architettura degli elaboratori", "Algoritmi"};

    temp = tempY = head;
    system(CLEAR);

    printf("\t\t\t ---- INSERISCI UNO STUDENTE ----\n\n");
    newStudent = (TypeStudent*) malloc(sizeof(TypeStudent)); // Allocco lo spazio per uno studente e controllo la malloc
    if (newStudent == NULL) {
        printf("Errore durante l\'allocazione dinamica della memoria");
        freeMemory(head);
        exit(EXIT_FAILURE);
    }

    if (isEmpty(head)) { // Se la lista principale è vuota stampo un errore
        printf("Errore, la lista e\' vuota. Premere invio per continuare...");
        getchar();
        return;
    } else { // Se la lista principale non è vuota
        printf("Inserisci l\'anno in cui inserire lo studente: ");
        check = scanf("%d", &year);
        year = checkValue(year, check, 1088, INT_MAX);
        while (temp != NULL && found != 1) { // Controllo se l'anno cercato è presente nella lista principale (MIGLIORARE)
            if (year == temp->year)
                found = 1;
            else
                temp = temp->next;
        }
        if (!found) { // Se non trovo l'anno in cui inserire lo studente
            printf("Errore, anno cercato non trovato. Premere invio per continuare....");
            free(newStudent);
            getchar();
            return;
        }
        temp->nStudents++; // Incremento il numero di studenti iscritti all'anno corrente
        if (temp->nStudents > temp->maxStudents && temp->code == 0) { // Se c'è il numero programmato controllo se c'è ancora posto
            printf("Errore, il numero massimo di studenti per l\'anno e\' stato raggiunto.\n");
            printf("Premere invio per continuare...");
            temp->nStudents--;
            free(newStudent);
            getchar();
            return;
        }
        printf("Inserisci la matricola: ");
        check = scanf("%d", &newStudent->code);
        newStudent->code = checkValue(newStudent->code, check, 0, INT_MAX);

        while (tempY != NULL) { // Controllo che la matricola non esista già nell'archivio
            tempS = tempY->student;
            while (tempS != NULL) {
                if (newStudent->code == tempS->code) {
                    printf("Errore, matricola %d gia\' presente nell\'archivio!", newStudent->code);
                    printf("\nPremere un tasto per continuare");
                    free(newStudent);
                    getchar();
                    return;
                }
                tempS = tempS->next;
            }
            tempY = tempY->next;
        }

        newStudent->next = temp->student; // Faccio puntare il next del nuovo studente a quello che puntava prima lo studente precedente
        temp->student = newStudent; // Faccio puntare lo studente precedente al nuovo studente

        printf("Inserisci il nome: ");
        fgets(newStudent->name, MAX, stdin);
        length = strlen(newStudent->name) - 1; // Rimuovo lo "\n" alla fine della stringa letta con la fgets
            if (newStudent->name[length] == '\n')
                newStudent->name[length] = '\0';

        printf("Inserisci il cognome: ");
        fgets(newStudent->surname, MAX, stdin);
        length = strlen(newStudent->surname) - 1;
            if (newStudent->surname[length] == '\n')
                newStudent->surname[length] = '\0';

        printf("Inserisci l'indirizzo: ");
        fgets(newStudent->address, MAX, stdin);
        length = strlen(newStudent->address) - 1;
            if (newStudent->address[length] == '\n')
                newStudent->address[length] = '\0';

        printf("\nInserisci -1 se l'esami non e\' stato svolto\n");
        for (i = 0; i < N_ESAMI; i++) {
            printf("Inserisci il voto di %s: ", nomiesami[i]);
            check = scanf("%d", &newStudent->voti[i]);
            newStudent->voti[i] = checkValue(newStudent->voti[i], check, -1, 30);
        }
    }

    return;
}

void printList(TypeYear *head) // Questa funzione stampa l'archivio
{
    TypeYear *temp;
    TypeStudent *tempS;
    int i;
    char nomiesami[][50] = {"Programmazione", "Inglese", "Analisi", "Algebra", "Architettura degli elaboratori", "Algoritmi"};


    system(CLEAR);
    printf("\t\t\t ---- VISUALIZZA ARCHIVIO ----\n");
    if (isEmpty(head)) { // Se la lista principale è vuota stampo un errore
        printf("\nErrore, la lista e\' vuota. Premere invio per continuare...");
        getchar();
        return;
    } else { // Se la lista principale non è vuota
        temp = head;
        while(temp != NULL) {
            tempS = temp->student; // Mi posiziono nella lista secondaria dell'anno temp
            printf("\nAnno: %d-%d", temp->year, temp->year+1);
            printf(" - Iscritti: %d - Numero Programmato: ", temp->nStudents); temp->code == 0 ? printf("si") : printf("no");
            while (tempS != NULL) {
                printf("\n\n\tMatricola: %d", tempS->code);
                printf("\n\tNome: %s", tempS->name);
                printf("\n\tCognome: %s", tempS->surname);
                printf("\n\tIndirizzo: %s", tempS->address);
                for (i = 0; i < N_ESAMI; i++) {
                    if (tempS->voti[i] == -1 || tempS->voti[i] < 18)
                        printf("\n\tEsame di %s non svolto o superato", nomiesami[i]);
                    else
                        printf("\n\tVoto di %s: %d", nomiesami[i], tempS->voti[i]);
                }
                tempS = tempS->next; // Scorro la lista secondaria
            }
            printf("\n");
            temp = temp->next; // Scorro la lista principale
        }
    }

    getchar();
    return;
}

void cancel(TypeYear *head) // Questa funzione cancella uno studente
{
    int codeDel, check, found = 0;
    TypeYear *temp;
    TypeStudent *tempS, *prev = NULL;

    system(CLEAR);
    printf("\t\t\t ---- ELIMINA STUDENTE ----\n\n");

    if (isEmpty(head)) { // Se la lista è vuota stampo un errore
        printf("Errore, la lista e\' vuota. Premere invio per continuare...");
        getchar();
        return;
    } else { // Se la lista non è vuota cerco lo studente
        temp = head;
        printf("Inserire il numero di matricola dello studente da eliminare: ");
        check = scanf("%d", &codeDel);
        codeDel = checkValue(codeDel, check, 0, INT_MAX);

        while (temp != NULL && found != 1) {
            tempS = temp->student;
            while (tempS != NULL && found != 1) {
                if (tempS->code == codeDel) { // Se la matricola corrisponde a uno presente nell'archivio
                    if (prev == NULL) // Se l'elemento è in testa
                        temp->student = tempS->next;
                    else { // Se l'elemento non è in testa
                        prev->next = tempS->next;
                    }
                    found = 1;
                    temp->nStudents--; // Diminuisco il numero di studenti dell'anno
                    free(tempS); // Libero la memoria
                }
                if (!found) { // Se non ho trovato, continuo a scorrere la lista secondaria
                    prev = tempS;
                    tempS = tempS->next;
                }
            }
            if (!found)
                temp = temp->next;
        }
        if (!found) { // Se alla fine non ho trovato niente stampo un errore
        printf("Errore, la matricola cercata non esiste.\nPremere invio per continuare...");
        getchar();
        return;
    }
    }
    return;
}
