#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#define N_CARTE 52
#define INGAME 1
#define OUT 0
#define LOST -1
#define MIN 10

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

typedef struct {
    int carta[N_CARTE]; // Dichiaro un array di N_CARTE elementi che userò come mazzo
    int testa;
    int coda;
} TipoMazzo;
typedef struct {
    char name[100];
    int points; //
    int carta[5];
    int puntata;
    int bilancio;
    int stato; // 1 se è in partita e 0 se ha abbandonato
} TipoPlayer;

// Definisco i prototipi delle funzioni
int checkValue(int value, int check, int min, int max);
void clearBuffer(void);
void printLine(void);
void creaMazzo(TipoMazzo *mazzo);
void mescola(TipoMazzo *mazzo);
void distribuisci(TipoMazzo *mazzo, TipoPlayer *players, int nplayers);
void stampaMano(TipoPlayer *player, int currentPlayer);
void initializePlayers(TipoPlayer *players, int nplayers, int bilancio, int *piatto, int *nPartita);
void rilancia(TipoPlayer *players, int currentPlayer, int *puntataMinima, int *piatto);
void abbandona(TipoPlayer *players, TipoMazzo *mazzo, int currentPlayer);
void printCurrent (TipoPlayer *players, int nplayers, int *piatto);
void vedi(TipoPlayer *players, int puntataMinima, int i);
void cambiaCarte(TipoMazzo *mazzo, TipoPlayer *players, int currentPlayer);
int puntimano(int *mano);
int puntiseme(int carta);
int puntivalore(int carta);

int main(void)
{
    int nplayers, i, p, check, length, money, scelta, piatto, puntataMinima = 0, k, f, fineTurno = 0, found = 0, activePlayers = 0;
    int winner, fuori = 0, pos, option, nPartita = 0;
    TipoPlayer *players;
    TipoMazzo mazzo;

    srand((unsigned) time(NULL));

    printf("\t\t\t ---- GIUOCO DEL POKER ----\n\n");
    printf("Inserire il numero di giocatori con cui si vuole giocare: ");
    check = scanf("%d", &nplayers);
    nplayers = checkValue(nplayers, check, 2, 6);

    players = (TipoPlayer*) malloc(nplayers * sizeof(TipoPlayer));
    if (players == NULL) {
        printf("Errore durante l\'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }

    clearBuffer();
    for (i = 0; i < nplayers; i++) {
        printf("Giocatore numero %d)\n\tInserisci il tuo nome: ", i+1);
        fgets(players[i].name, 100, stdin);
        length = strlen(players[i].name) - 1;
        if (players[i].name[length] == '\n')
            players[i].name[length] = '\0';
    }
    printf("\nCon quanti dollari ($) si desidera iniziare? ");
    printf("\n10$ vengono usati per l\'entrata in partita\nScelta: ");
    check = scanf("%d", &money);
    money = checkValue(money, check, 50, 10000000);

    while (fuori + 1 < nplayers) {

    piatto = puntataMinima = 0;
    initializePlayers(players, nplayers, money, &piatto, &nPartita);
    creaMazzo(&mazzo);
    mescola(&mazzo);
    distribuisci(&mazzo, players, nplayers);
    nPartita++;
    system(CLEAR);

    for (f = 0; f < 3; f++) { // FOR INIZIO
        if (f == 2 || f == 1)
            fineTurno = 0;
        while (fineTurno != 1) {// WHILE START
            for (i = 0; i < nplayers; i++) {
                if (players[i].stato == INGAME) { // Inizio if
                printf("FASE: %d, FINETURNO: %d, N_P: %d\n\n",f,fineTurno,i); // ELIMINARE
                printCurrent(players, nplayers, &piatto);
                printf("Giocatore %d (%s) e\' il tuo turno:\n", i, players[i].name);
                stampaMano(players, i);

                if (f != 1)
                    printf("\n\tPremere 1 per rilanciare");
                printf("\n\tPremere 2 per vedere");
                printf("\n\tPremere 3 per abbandonare");
                if (f == 1)
                    printf("\n\tPremere 4 per cambiare carte");
                printf("\n\tScelta: ");
                check = scanf("%d", &scelta);
                scelta = checkValue(scelta, check, 1, 4);
                printf("\n\n");
                switch (scelta) {
                    case 1 :
                        rilancia(players, i, &puntataMinima, &piatto);
                        break;
                    case 2 :
                        vedi(players, puntataMinima, i);
                        break;
                    case 3 :
                        abbandona(players, &mazzo, i);
                        break;
                    case 4 :
                        cambiaCarte(&mazzo, players, i);
                        break;
                    default :
                        printf("Errore, scelta non valida");
                        exit(EXIT_FAILURE);
                }
                system(CLEAR);

            } int abbandonato = 0;
            for (p = 0; p < nplayers && found != 1; p++) {
                if (players[p].stato == OUT) {
                    abbandonato++;
                } else if (players[p].stato == INGAME)
                    pos = p;
            }
            if (nplayers - 1 == abbandonato) {
                    system(CLEAR);
                    printf("Tutti i giocatori tranne uno hanno abbandonato la partita, di conseguenza vince: ");
                    printf("\n- Giocatore %d (%s)", pos, players[pos].name);
                    f = 4;
                    fineTurno = 1;
                    i = nplayers + 1;
                    printf("\n\n\nPremi 0 per continuare a giocare o 1 per uscire: ");
                    check = scanf("%d", &option);
                    option = checkValue(option, check, 0, 1);
                    if (option == 1)
                        exit(EXIT_SUCCESS);
            }
            } // Fine if
            found = 0;
            for (k = 0; k < nplayers && found != 1; k++) {
                    if (players[k].puntata == puntataMinima) {
                        fineTurno = 1;
                    } else {
                        fineTurno = 0;
                        found = 1;
                    }
                } // FINE FOR FINETURNO
            for (k = 0; k < nplayers; k++) {
                if (players[k].stato == 1)
                    activePlayers++;
            }
        } // WHILE FINISH
        winner = 0;
        if (f == 2) {
            for (p = 0; p < nplayers; p++) {
                if (players[p].bilancio <= 0) {
                    players[p].stato = LOST;
                    fuori++;
                }
                if (players[p].stato != OUT || players[p].stato != LOST) {
                    players[p].points = puntimano(players[p].carta);
                    if (players[p].points > winner) {
                        winner = players[p].points;
                        pos = p;
                    }
                }
            }
            printf("\nHa vinto %s con la seguente mano!\n\n",players[pos].name);
            stampaMano(players, pos);
            printf("\n\n\nPremi 0 per continuare a giocare o 1 per uscire: ");
            check = scanf("%d", &option);
            option = checkValue(option, check, 0, 1);
            if (option == 1)
                exit(EXIT_SUCCESS);
        }
    } // FINE FOR FASI
    } // FINE WHILE PARTITA
    return 0;
}

void clearBuffer(void) // Definisco una funzione per pulire il buffer da tastiera che è completamente portabile
{
    char ch;
    do {
        ch = getchar();
    } while (('\n' != ch) && (EOF != ch));
}

int checkValue(int n, int check, int min, int max) // Questa funzione controlla che l'input dell'utente sia valido
{
    while (n < min || n > max || check != 1) {
        clearBuffer();
        printf("Errore, devi inserire un numero valido compreso tra %d e %d: ", min, max);
        check = scanf("%d", &n);
    }

    return n;
}

void creaMazzo(TipoMazzo *mazzo)
{
    int i;

    for (i = 0; i < N_CARTE; i++)
        mazzo->carta[i] = i;
    mazzo->testa = 0;
    mazzo->coda = N_CARTE - 1;
    return;
}

void mescola(TipoMazzo *mazzo)
{
    int i, temp, num;

    for(i = 0; i < N_CARTE; i++) {
        do {
            num = rand() % 52;
        } while (num == mazzo->carta[i]);
        temp = mazzo->carta[num];
        mazzo->carta[num] = mazzo->carta[i];
        mazzo->carta[i] = temp;
    }
    return;
}

void distribuisci(TipoMazzo *mazzo, TipoPlayer *players, int nplayers)
{
    int i, j;

    for (i = 0; i < nplayers; i++) {
        for (j = 0; j < 5; j++, mazzo->testa++) {
            players[i].carta[j] = mazzo->carta[mazzo->testa];
        }
    }
    return;
}

void cambiaCarte(TipoMazzo *mazzo, TipoPlayer *players, int currentPlayer)
{
    int i, pos, nCarte, check ;

    printf("Inserire il numero di carte che si desidera cambiare: ");
    check = scanf("%d", &nCarte);
    nCarte = checkValue(nCarte, check, 1, 5);

    for (i = 0; i < nCarte; i++) {
        printf("Inserire la posizione della %d° carta da cambiare: ", i+1);
        check = scanf("%d", &pos);
        pos = checkValue(pos, check, 1, 5);
        pos -= 1;

        mazzo->carta[(mazzo->coda+1)%N_CARTE] = players[currentPlayer].carta[pos];
        mazzo->coda = (mazzo->coda+1) % N_CARTE;
        players[currentPlayer].carta[pos] = mazzo->carta[mazzo->testa];
        mazzo->testa++;
    }

    return;
}

void stampaMano(TipoPlayer *player, int currentPlayer)
{
    int i;

    for (i = 0; i < 5; i++) {
        if (player[currentPlayer].carta[i] < 13) { // Carta di cuori
            if (player[currentPlayer].carta[i] == 0)
                printf("Asso di Cuori");
            else if (player[currentPlayer].carta[i] < 10)
                printf("%d di Cuori", player[currentPlayer].carta[i]);
            else if (player[currentPlayer].carta[i] == 10)
                printf("Jack (J) di cuori");
            else if (player[currentPlayer].carta[i] == 11)
                printf("Donna (Q) di Cuori");
            else if (player[currentPlayer].carta[i] == 12)
                printf("Re (K) di Cuori");
        }
        else if (player[currentPlayer].carta[i] < 26) { // Carta di Quadri
                if (player[currentPlayer].carta[i] == 13)
                    printf("Asso di Quadri");
                else if (player[currentPlayer].carta[i] < 23)
                    printf("%d di Quadri", player[currentPlayer].carta[i]-12);
                else if (player[currentPlayer].carta[i] == 23)
                    printf("Jack (J) di Quadri");
                else if (player[currentPlayer].carta[i] == 24)
                    printf("Donna (Q) di Quadri");
                else if (player[currentPlayer].carta[i] == 25)
                    printf("Re (K) di Quadri");
        }
        else if (player[currentPlayer].carta[i] < 39) { // Carta di Fiori
            if (player[currentPlayer].carta[i] == 26)
                printf("Asso di Fiori");
            else if (player[currentPlayer].carta[i] < 36)
                printf("%d di Fiori", player[currentPlayer].carta[i]-25);
            else if (player[currentPlayer].carta[i] == 36)
                printf("Jack (J) di fiori");
            else if (player[currentPlayer].carta[i] == 37)
                printf("Donna (Q) di Fiori");
            else if (player[currentPlayer].carta[i] == 38)
                printf("Re (K) di Fiori");
        }
        else if (player[currentPlayer].carta[i] < N_CARTE) { // Carta di Picche
            if (player[currentPlayer].carta[i] == 39)
                printf("Asso di Picche");
            else if (player[currentPlayer].carta[i] < 49)
                printf("%d di Picche", player[currentPlayer].carta[i]-38);
            else if (player[currentPlayer].carta[i] == 49)
                printf("Jack (J) di Picche");
            else if (player[currentPlayer].carta[i] == 50)
                printf("Donna (Q) di Picche");
            else if (player[currentPlayer].carta[i] == 51)
                printf("Re (K) di Picche");
        }
        i == 4 ? printf(" ") : printf(" - ");

    }

    return;
}

void initializePlayers(TipoPlayer *players, int nplayers, int bilancio, int *piatto, int *nPartita)
{
    int i;

    for (i = 0; i < nplayers; i++) {
        players[i].stato = 1;
        if (*nPartita == 0)
            players[i].bilancio = bilancio - MIN;
        else
            players[i].bilancio -= MIN;
        *piatto += MIN;
        players[i].puntata = 0;
    }

    return;
}

void rilancia(TipoPlayer *players, int currentPlayer, int *puntataMinima, int *piatto)
{

    int check, money, scelta, temp = 0, temp2 = 0;

    printf("Quanto vuoi scommettere? ");
    check = scanf("%d", &money);
    money = checkValue(money, check, 0, players[currentPlayer].bilancio);

    temp2 = players[currentPlayer].puntata;
    temp = *puntataMinima - players[currentPlayer].puntata;
    players[currentPlayer].puntata += money;

    while (*puntataMinima > players[currentPlayer].puntata) {
        players[currentPlayer].puntata  = temp2;
        printf("\nErrore, devi fare una puntata minima pari ad almeno %d", temp);
        printf("\n\nPremi 1 per inserire un nuovo importo\nPremi 2 per foldare e abbandonare la partita");
        printf("\nScelta: ");
        check = scanf("%d", &scelta);
        scelta = checkValue(scelta, check, 1, 2);

        switch(scelta) {
            case 1 :
                printf("\nNuovo importo (minimo %d): ", temp);
                check = scanf("%d", &money);
                money = checkValue(money, check, 0, players[currentPlayer].bilancio);
                temp = *puntataMinima - players[currentPlayer].puntata;
                players[currentPlayer].puntata += money;
            case 2 :
                ;
        }
    }
    players[currentPlayer].bilancio -= money;
    *puntataMinima = players[currentPlayer].puntata;
    *piatto += money;

    return;
}

void vedi(TipoPlayer *players, int puntataMinima, int i)
{
    int togli;

    togli = puntataMinima - players[i].puntata;
    if (togli > players[i].bilancio)
        printf("Errore, non hai abbastanza soldi per vedere le carte.");
    else {
        players[i].bilancio -= togli;
        players[i].puntata += togli;
    }


    return;
}

void abbandona(TipoPlayer *players, TipoMazzo *mazzo, int currentPlayer)
{
    int j;

    players[currentPlayer].stato = OUT;

    for (j = 0; j < 5; j++) {
        mazzo->coda = (mazzo->coda + 1) % N_CARTE;
        players[currentPlayer].carta[j] = mazzo->carta[mazzo->coda];
    }

    return;
}

void printLine(void)
{
	printf("\n________________________________________________________________________________\n");
}

void printCurrent (TipoPlayer *players, int nplayers, int *piatto)
{
    int i, conta = 0;

    printLine();
    printf("Sul piatto: %d$\n\n", *piatto);
    printf("Giocatori in partita: ");
    for (i = 0; i < nplayers; i++)
        if (players[i].stato == INGAME) {
            conta++;
            printf("\nGiocatore %d (%s) - Puntata: %d - Bilancio: %d", i, players[i].name, players[i].puntata, players[i].bilancio);
        }
    if (conta != nplayers) {
        printf("\n\nGiocatori che hanno abbandonato la partita:  ");
        for (i = 0; i < nplayers; i++)
            if (players[i].stato == OUT)
                printf("\nGiocatore %d (%s) - Puntata: %d - Bilancio: %d", i, players[i].name, players[i].puntata, players[i].bilancio);
    }
    printLine();
    return;
}

int puntivalore (int carta)
{
    carta = carta % 13;
    if (carta==0)
        return 65;
    else
        return carta * 5;
}

int puntiseme(int carta)
{
    return 4 - (carta / 13);
}

int puntimano(int *mano)
{
    int i,j,min,tmp, temp, punti = 0;

    for (i = 0; i < 3; i++) { // questo ciclo ordina le carte per valore (asso a destra)
        min = i;
        for (j = i+1; j < 4; j++) {
            if (puntivalore(mano[min]) < puntivalore(mano[j]))
                min = j;
        }
        temp = mano[min];
        mano[min] = mano[i];
        mano[i] = temp;
    }

    // Poker -
    if (mano[0] % 13 == mano[3] % 13 || mano[1] % 13 == mano[4] % 13) {
        punti = 700 + puntivalore(mano[i] + 4);
        return punti;
    }
    // Colore -
    if (mano[0] / 13 == mano[1] / 13 && mano[1] / 13 == mano[2] / 13 && mano[2] / 13 == mano[3] / 13 && mano[3] / 13 == mano[4] / 13){
        tmp = 0;
        for(i=0;i<5;i++)
            if (puntivalore(mano[i]) > tmp)
                tmp = puntivalore(mano[i]);
        punti = 600 + puntiseme(mano[0]) + tmp;
        return punti;
    }
    // Full -
    temp = -2;
    if (mano[0] % 13 == mano[1] % 13 && mano[2] % 13 == mano[4] % 13)
        temp = 2;
    if (mano[3] % 13 == mano[4] % 13 && mano[0] % 13 == mano[2] % 13)
        temp = 0;
    if (temp != -2) {
        for (i = temp; i < temp + 3; i++) {
            if (tmp < puntiseme(mano[i]))
                tmp = puntiseme(mano[i]);
        }
        punti = 500 + tmp + puntivalore(mano[2]);
        return punti;
    }
    // Scala -
    min = 0;
    for (i = 0; i < 5; i++)
        if ((1 + mano[i] % 13) % 13 == mano[(i+1) %5] % 13)
            min++;
    if (min == 4) {
        j = tmp=0;
        for(i = 0; i < 5; i++)
            if (j < puntivalore(mano[i])) {
                j = puntivalore(mano[i]);
                tmp = puntiseme(mano[i]);
            }
        punti = 400 + j + tmp;
        return punti;
    }
    // Tris (AAA??,?AAA?,??AAA) -
    temp = -2, tmp = 0;
    if (mano[0] % 13 == mano[2] % 13)
        temp = 0;
    if (mano[1] % 13 == mano[3] % 13)
        temp = 1;
    if (mano[2] % 13 == mano[4] % 13)
        temp = 2;
    if (temp != -2) {
        for (i = temp; i < temp + 3; i++) {
            if (tmp < puntivalore(mano[i])) {
                tmp = puntiseme(mano[i]);
            }
        }
        punti = 300 + tmp + puntivalore(mano[temp]);
        return punti;
    }
    // Doppia Coppia -
    min=tmp=-1;
    for (i=0;i<4;i++) // ciclo che cerca le coppie
        if (mano[i]%13==mano[i+1]%13){
            if (min!=-1) tmp=min;
            min=i;}
    if (tmp!=-1){// doppia coppia
        if (puntivalore(mano[min])>puntivalore(mano[tmp])) j=min;
        else j=tmp;
        if (puntiseme(mano[j])>puntiseme(mano[j+1])) return 200+puntivalore(mano[j])+puntiseme(mano[j]);
        else return 200+puntivalore(mano[j])+puntiseme(mano[j+1]);}
    if (min!=-1){ // coppia
        if (puntiseme(mano[min])>puntiseme(mano[min+1])) return 100+puntivalore(mano[min])+puntiseme(mano[min]);
        else return 100+puntivalore(mano[min])+puntiseme(mano[min+1]);}
    if (mano[0]%13==0) return 65+puntiseme(mano[0]);
    else return puntivalore(mano[4])+puntiseme(mano[4]);

}
