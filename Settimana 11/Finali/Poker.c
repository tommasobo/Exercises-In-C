/*
    * Autore: Tommaso Bonato
    * Numero matricola: 0000723575
    * E-Mail: tommaso.bonato@studio.unibo.it

    * Questo programma simula una partita di Poker
*/

/*
* Ho deciso di organizzare la partita in 3 fasi come stabilito dal Poker tradizionale:
*   - Prima fase: i giocatori vedono le carte e possono rilanciare, abbandonare o vedere (ovvero procedere alla prossima fase).
*   La prima fase prosegue finchè tutti non hanno puntato la stessa soglia o finchè rimane solo un giocatore
*   - Seconda fase: i giocatori possono cambiare un numero di carte a piacimento, abbandonare o procedere alla prossima fase
*   - Terza fase: i giocatori possono eseguire le stesse operazioni della prima fase e alla fine un giocatore vince in base alla propria mano
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#define N_CARTE 52 // Numero di carte nel mazzo
#define INGAME 1 // Stato per indicare che un giocatore è in gioco
#define OUT 0 // Stato per indicare che un giocatore ha abbandonato il turno
#define LOST -1 // Stato per indicare che un giocatore ha perso
#define MIN 10 // $ necessari per entrare in gioco

// Definisco delle condizioni al pre-processore per permettere il funzionamento della funzione pausa sia su Windows sia sugli altri OS
#ifdef _WIN32
#define CLEAR "cls"
#else // Negli altri OS
#define CLEAR "clear"
#endif

typedef struct { // Considero il mazzo come una lista statica ad anello di 52 elementi divisi in 4 righe. Ogni riga indica un seme
    int carta[N_CARTE]; // Dichiaro un array di N_CARTE elementi che userò come mazzo
    int testa; // Indica l'inizio del mazzo
    int coda; // Indica la fine del mazzo
} TipoMazzo;
typedef struct {
    char name[100];
    int points;
    int carta[5];
    int puntata;
    int bilancio;
    int stato; // può essere OUT, LOST o INGAME (vedi commenti precedenti per dettagli)
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
void rilancia(TipoPlayer *players, int currentPlayer, int *puntataMinima, int *piatto, TipoMazzo *mazzo);
void abbandona(TipoPlayer *players, TipoMazzo *mazzo, int currentPlayer);
void printCurrent (TipoPlayer *players, int nplayers, int *piatto);
void vedi(TipoPlayer *players, int puntataMinima, int i, int *piatto);
void cambiaCarte(TipoMazzo *mazzo, TipoPlayer *players, int currentPlayer);
int puntimano(int *mano);
int puntiseme(int carta);
int puntivalore(int carta);

int main(void)
{
    int nplayers, i, p, check, length, money, scelta, piatto, puntataMinima = 0, k, f, fineTurno = 0, found = 0, activePlayers = 0;
    int winner, fuori = 0, pos, option, nPartita = 0, abbandonato = 0;
    TipoPlayer *players;
    TipoMazzo mazzo;

    srand((unsigned) time(NULL));

    printf("\t\t\t ---- GIUOCO DEL POKER ----\n\n");
    printf("Inserire il numero di giocatori con cui si vuole giocare: ");
    check = scanf("%d", &nplayers);
    nplayers = checkValue(nplayers, check, 2, 6);

    players = (TipoPlayer*) malloc(nplayers * sizeof(TipoPlayer)); // Alloco lo spazio per n giocatori
    if (players == NULL) {
        printf("Errore durante l\'allocazione dinamica della memoria");
        exit(EXIT_FAILURE);
    }

    clearBuffer();
    for (i = 0; i < nplayers; i++) { // Richiedo il nome dei giocatori
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

    while (fuori + 1 < nplayers) { // La partita prosegue finchè tutti tranne un giocatore sono senza soldi

        piatto = puntataMinima = 0;
        // Inizializzo i giocatori, il mazzo e distribuisco le carte prima di ogni partita
        initializePlayers(players, nplayers, money, &piatto, &nPartita);
        creaMazzo(&mazzo);
        mescola(&mazzo);
        distribuisci(&mazzo, players, nplayers);
        nPartita++;
        system(CLEAR);

        for (f = 0; f < 3; f++) { // Eseguo un ciclo for per le 3 fasi di gioco
            if (f == 2 || f == 1)
                fineTurno = 0;
            while (fineTurno != 1) { // Se sono nella fase dei rilanci proseguo finchè tutti non puntano la stessa soglia
                for (i = 0; i < nplayers; i++) {
                    if (players[i].stato == INGAME) { // Inizio if
                    printf("FASE: %d, TURNO %d, N_P: %d",f,fineTurno,i);
                    printCurrent(players, nplayers, &piatto); // Stampo un "overview" della situazione
                    printf("Giocatore %d (%s) e\' il tuo turno:\n", i, players[i].name);
                    stampaMano(players, i); // Stampo la mano del giocatore corrente

                    printf("\n");
                    if (f != 1) // Se non sono nella seconda fase
                        printf("\n\tPremere 1 per rilanciare");
                    printf("\n\tPremere 2 per vedere (punta il minimo e vai alla prossima fase)");
                    printf("\n\tPremere 3 per abbandonare");
                    if (f == 1) // Se sono nella seconda fase
                        printf("\n\tPremere 4 per cambiare carte");
                    printf("\n\tScelta: ");
                    check = scanf("%d", &scelta);
                    scelta = checkValue(scelta, check, 1, 4);
                    printf("\n\n");
                    switch (scelta) { // Controllo quale operazione vuole svolgere l'utente
                        case 1 :
                            rilancia(players, i, &puntataMinima, &piatto, &mazzo);
                            break;
                        case 2 :
                            vedi(players, puntataMinima, i, &piatto);
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

                }
                abbandonato = 0; // Numero di giocatori che hanno abbandonato la partita
                for (p = 0; p < nplayers && found != 1; p++) { // Controllo quanti giocatori hanno abbandonato e chi è in gioco
                    if (players[p].stato == OUT) {
                        abbandonato++;
                    } else if (players[p].stato == INGAME)
                        pos = p;
                }
                if (nplayers - 1 == abbandonato) { // Se solo un giocatore non ha abbandonato
                        system(CLEAR);
                        printf("Tutti i giocatori tranne uno hanno abbandonato la partita, di conseguenza vince: ");
                        printf("\n- Giocatore %d (%s)", pos, players[pos].name);
                        f = 4;
                        fineTurno = 0;
                        i = nplayers + 1;
                        printf("\n\n\nPremi 0 per continuare a giocare o 1 per uscire: ");
                        check = scanf("%d", &option);
                        option = checkValue(option, check, 0, 1);
                        if (option == 1)
                            exit(EXIT_SUCCESS);
                }
                } // Fine for turno giocatori
                found = 0;
                for (k = 0; k < nplayers && found != 1; k++) { // Controllo se tutti i giocatori hanno puntato il minimo
                        if (players[k].puntata == puntataMinima) {
                            fineTurno = 1;
                        } else {
                            fineTurno = 0;
                            found = 1;
                        }
                    } // Fine for "fineTurno"
                for (k = 0; k < nplayers; k++) { // Controllo quanti sono i giocatori attivi
                    if (players[k].stato == 1)
                        activePlayers++;
                }
            } // WHILE FINISH
            winner = 0;
            if (f == 2) { // Se sono nell'ultima fase di gioco controllo chi è il vincitore
                for (p = 0; p < nplayers; p++) {
                    if (players[p].bilancio <= 0) { // Se un giocatore ha finito i soldi l'ho dichiaro sconfitto
                        players[p].stato = LOST;
                        fuori++;
                    }
                    if (players[p].stato != OUT || players[p].stato != LOST) { // Se un giocatore è ancora in gioco
                        players[p].points = puntimano(players[p].carta); // Calcolo i punti della sua mano
                        if (players[p].points > winner) { // Calcolo il giocatore con più punti
                            winner = players[p].points;
                            pos = p;
                        }
                    }
                    if (fuori == nplayers || nplayers - 1 <= fuori) {
                        system(CLEAR);
                        printf("Tutti i giocatori sono senza soldi, fine partita!");
                    }
                }
                printf("\nHa vinto %s con la seguente mano!\n\n",players[pos].name);
                players[pos].bilancio += piatto;
                f = 4;
                fineTurno = 0;
                i = nplayers + 1;
                stampaMano(players, pos);
                printf("\n\n\nPremi 0 per continuare a giocare o 1 per uscire: ");
                check = scanf("%d", &option);
                option = checkValue(option, check, 0, 1);
                if (option == 1)
                    exit(EXIT_SUCCESS);
            }
        } // Fine for fasi partita
    } // Fine while partita
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

void creaMazzo(TipoMazzo *mazzo) // Questa funzione crea un mazzo di carte e inizializza testa e coda
{
    int i;

    for (i = 0; i < N_CARTE; i++)
        mazzo->carta[i] = i;
    mazzo->testa = 0;
    mazzo->coda = N_CARTE - 1;
    return;
}

void mescola(TipoMazzo *mazzo) // Questa funzione mescola il mazzo
{
    int i, temp, num;

    for(i = 0; i < N_CARTE; i++) { // Per ogni carta eseguo uno swap con un'altra casuale presente nel mazzo
        do {
            num = rand() % 52;
        } while (num == mazzo->carta[i]);
        temp = mazzo->carta[num];
        mazzo->carta[num] = mazzo->carta[i];
        mazzo->carta[i] = temp;
    }
    return;
}

void distribuisci(TipoMazzo *mazzo, TipoPlayer *players, int nplayers) // Questa funzione distribuisce 5 carte ad ogni giocatore
{
    int i, j;

    for (i = 0; i < nplayers; i++) {
        for (j = 0; j < 5; j++, mazzo->testa++) {
            players[i].carta[j] = mazzo->carta[mazzo->testa]; // Prendo le carte dalla testa del mazzo e le salvo nella mano del giocatore
        }
    }
    return;
}

// Questa funzione cambia n carte di un giocatore con altre n presenti nel mazzo
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

        mazzo->carta[(mazzo->coda+1)%N_CARTE] = players[currentPlayer].carta[pos]; // Metto la carta da cambiare in fondo al mazzo
        mazzo->coda = (mazzo->coda+1) % N_CARTE; // Aumento di uno la coda del mazzo
        players[currentPlayer].carta[pos] = mazzo->carta[mazzo->testa]; // Prendo dalla testa del mazzo una nuova carta
        mazzo->testa++;
    }

    return;
}

// Questa funzione stampa la mano di un giocatore
// Nota: la funzione è migliorabile riducendo il numero di if, ma purtroppo non ho avuto tempo per farlo
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

// Questa funzione inizializza i parametri base di un giocatore
void initializePlayers(TipoPlayer *players, int nplayers, int bilancio, int *piatto, int *nPartita)
{
    int i;

    for (i = 0; i < nplayers; i++) {
        players[i].stato = INGAME; // Imposto lo stato come in partita
        if (*nPartita == 0)
            players[i].bilancio = bilancio - MIN; // Tolgo dal bilancio l'entrata in partita
        else
            players[i].bilancio -= MIN;
        *piatto += MIN;
        players[i].puntata = 0; // Imposto la puntata a 0
    }

    return;
}

// Questa funzione si occupa dei rilanci eseguiti da un giocatore
void rilancia(TipoPlayer *players, int currentPlayer, int *puntataMinima, int *piatto, TipoMazzo *mazzo)
{

    int check, money, scelta, temp = 0, temp2 = 0;

    printf("Quanto vuoi scommettere? ");
    check = scanf("%d", &money);
    money = checkValue(money, check, 0, players[currentPlayer].bilancio);

    temp2 = players[currentPlayer].puntata; // Salvo in temp2 la puntata attuale
    temp = *puntataMinima - players[currentPlayer].puntata; // Salvo in temp il risultato
    players[currentPlayer].puntata += money; // Aumento la puntata del giocatore

    while (*puntataMinima > players[currentPlayer].puntata) { // Eseguo un ciclo while finchè la puntata non è uguale almeno alla puntata minima
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
                break;
            case 2 :
                abbandona(players, mazzo, currentPlayer);
                break;
        }
    }
    players[currentPlayer].bilancio -= money; // Toglo i soldi della puntata dal bilancio del giocatore
    *puntataMinima = players[currentPlayer].puntata; // Stabilisco la nuova puntataMinima che al massimo è uguale a quella precedente
    *piatto += money; // Aumento l'importo del piatto

    return;
}

// Questa funzione consente di eseguire la puntata minima per passare al turno successivo
void vedi(TipoPlayer *players, int puntataMinima, int i, int *piatto)
{
    int togli;

    togli = puntataMinima - players[i].puntata; // Soldi minimi da puntare
    if (togli > players[i].bilancio)
        printf("Errore, non hai abbastanza soldi per vedere le carte.");
    else {
        players[i].bilancio -= togli;
        players[i].puntata += togli;
        *piatto += togli;
    }


    return;
}

// Questa funzione fa uscire un giocatore dalla mano e rimette le carte nel mazzo
void abbandona(TipoPlayer *players, TipoMazzo *mazzo, int currentPlayer)
{
    int j;

    players[currentPlayer].stato = OUT; // Imposto lo stato del giocatore come "OUT" ovvero che ha abbandonato la mano

    for (j = 0; j < 5; j++) { // Rimetto le carte nel mazzo
        mazzo->coda = (mazzo->coda + 1) % N_CARTE;
        players[currentPlayer].carta[j] = mazzo->carta[mazzo->coda]; // Metto le carte in fondo al mazzo
    }

    return;
}

void printLine(void) // Questa funzione stampa una linea grande come la schermata del cmd
{
	printf("\n________________________________________________________________________________\n");
}

// Questa funzione stampa la situazione attuale della partita
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

/*  Per decretare il vincitore della mano ho assegnato ad ogni combinazione un punteggio univoco il cui massimo è 769 (assi di poker).
*   La combinazione di carte vale 100 punti: 700 per il poker, 600 per il colore, 500 per il full, 400 per la scala,
*   300 per il tris, 200 per la doppia coppia, 100 per la coppia. La carta più alta della combinazione inoltre vale da 5 a
*   65 punti (dal 2 all'asso), e il suo seme vale da 1 a 4.
*/

// Questa funzione restituisce i punti considerando il valore della carta indicata
int puntivalore (int carta)
{
    carta = carta % 13;
    if (carta==0)
        return 65;
    else
        return carta * 5;
}

// Questa funzione restituisce i punti considerando il seme della carta considerata
int puntiseme(int carta)
{
    return 4 - (carta / 13);
}

// Questa funzione calcola i punti della mano di un giocatore
int puntimano(int *mano)
{
    int i,j,min,tmp, temp, punti = 0;

    for (i = 0; i < 3; i++) { // Ordino le carte della mano mettendo l'asso a destra
        min = i;
        for (j = i+1; j < 4; j++) {
            if (puntivalore(mano[min]) < puntivalore(mano[j]))
                min = j;
        }
        temp = mano[min];
        mano[min] = mano[i];
        mano[i] = temp;
    }

    // Poker - Dato che le carte sono in ordine basta vedere se la prima è uguale alla quarta o se la seconda è uguale all'ultima
    if (mano[0] % 13 == mano[3] % 13 || mano[1] % 13 == mano[4] % 13) {
        punti = 700 + puntivalore(mano[i] + 4);
        return punti;
    }
    // Colore - Controllo se il seme delle carte è uguale
    if (mano[0] / 13 == mano[1] / 13 && mano[1] / 13 == mano[2] / 13 && mano[2] / 13 == mano[3] / 13 && mano[3] / 13 == mano[4] / 13){
        tmp = 0; // Valuto il valore massimo della mano
        for(i = 0; i < 5; i++)
            if (puntivalore(mano[i]) > tmp)
                tmp = puntivalore(mano[i]);
        punti = 600 + puntiseme(mano[0]) + tmp;
        return punti;
    }
    // Full - I due casi possibili sono XXYYY o YYYXX.
    temp = -2;
    if (mano[0] % 13 == mano[1] % 13 && mano[2] % 13 == mano[4] % 13) // Caso XXYYY
        temp = 2;
    if (mano[3] % 13 == mano[4] % 13 && mano[0] % 13 == mano[2] % 13) // Caso XXXYY
        temp = 0;
    if (temp != -2) {
        for (i = temp; i < temp + 3; i++) { // Calcolo il valore del seme
            if (tmp < puntiseme(mano[i]))
                tmp = puntiseme(mano[i]);
        }
        punti = 500 + tmp + puntivalore(mano[2]);
        return punti;
    }
    // Scala - Controllo se la prima carta è di 4 posti più indietro dell'ultima, con warp se si arriva al minimo o al massimo
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
    // Tris (XXX??,?XXX?,??XXX) - Controllo semplicemente i vari casi
    temp = -2, tmp = 0;
    if (mano[0] % 13 == mano[2] % 13) // Caso XXX??
        temp = 0;
    if (mano[1] % 13 == mano[3] % 13) // Caso ?XXX?
        temp = 1;
    if (mano[2] % 13 == mano[4] % 13) // Caso ??XXX
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
    // Doppia Coppia e Coppia
    min = tmp = -1;
    for (i = 0; i < 4; i++) // Questo ciclo cerca le coppie presenti nella mano
        if (mano[i] % 13 == mano[i+1] % 13){
            if (min != -1)
                tmp = min;
            min = i;
        }
    if (tmp != -1){ // Caso Doppia coppia
        if (puntivalore(mano[min]) > puntivalore(mano[tmp]))
            j = min;
        else
            j = tmp;
        if (puntiseme(mano[j]) > puntiseme(mano[j+1])) {
            punti = 200 + puntivalore(mano[j]) + puntiseme(mano[j]);
            return punti;
        }
        else {
            punti = 200 + puntivalore(mano[j]) + puntiseme(mano[j+1]);
            return punti;
        }
    }
    if (min != -1){ // Allora è una coppia
        if (puntiseme(mano[min]) > puntiseme(mano[min+1])) {
            punti = 100 + puntivalore(mano[min]) + puntiseme(mano[min]);
            return punti;
        }
        else {
            punti = 100 + puntivalore(mano[min]) + puntiseme(mano[min+1]);
            return punti;
        }
    }
    if (mano[0] % 13 == 0) { // Se il primo elemento è un asso e quindi tutte le altre carte sono più alte
        punti = 65 + puntiseme(mano[0]);
        return punti;
    }
    else {
        punti = puntivalore(mano[4]) + puntiseme(mano[4]); // Altrimenti controllo il l'ultima carta che è quella più alta
        return punti;
    }
}
