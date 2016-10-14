/* Esercizio 3, settimana 11
   Questo programma simula una partita a poker.
   Autore: Nicola Cielo Lugaresi Secci (mat. 0000718887)
   Data: 20/12/2014
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>
#define nshuffle 3
#define ch_tr 191
#define ch_bl 192
#define ch_br 217
#define ch_tl 218
#define ch_v 179
#define ch_o 196
#define ch_bm 193
#define ch_tm 194

/* Ogni giocatore ha puntatore a carattere che identifica il nome, un intero per il bilancio, uno per l'ultima puntata fatta,
   uno per i punti nella mano corrente, un array di 5 interi per la mano corrente (ogni intero identifica una carta, numerate
   da 0 a 51, dall'asso al re per cuori, quadri, fiori e picche nell'ordine) e un intero per lo stato (1 se in gioco, 0 se
   passa il turno, -1 se è stato eliminato).
   Considero il mazzo come una lista statica di 52 elementi, ad anello*/
typedef struct {int puntimano; int mano[5]; int bilancio; char nome[21]; int stato; int puntata; int ishuman;} player;
typedef struct {int carta[52];int testa;int ncarte;} s_mazzo;

void creamazzo(s_mazzo*mazzo){ // questa funzione crea un "mazzo"
    int i;
    for (i=0;i<52;i++) mazzo->carta[i]=i;
    mazzo->testa=0;
    mazzo->ncarte=52;}

void mescolamazzo(s_mazzo*mazzo){ // questa funzione mescola il mazzo
    int i,j,k,tmp;
    for (i=0;i<nshuffle;i++){ // per "nshuffle" volte:
        for(j=0;j<mazzo->ncarte;j++){ // per ogni carta nel mazzo:
            do k=rand()%mazzo->ncarte; // scegli una carta diversa e scambiale
            while (k==j);
            tmp=mazzo->carta[(mazzo->testa+j)%mazzo->ncarte];
            mazzo->carta[(mazzo->testa+j)%mazzo->ncarte]=mazzo->carta[(mazzo->testa+k)%mazzo->ncarte];
            mazzo->carta[(mazzo->testa+k)%mazzo->ncarte]=tmp;}}}

void daicarte(int*mano,s_mazzo*mazzo){ // questa funzione da le carte al giocatore
    int i;
    for (i=0;i<5;i++) // considera ogni carta nella mano
        if (mano[i]==-1){ // se la carta considerata è nulla (cioè la carta non è presente)
            mano[i]=mazzo->carta[mazzo->testa]; // toglie dal mazzo una carta e la mette nella mano
            mazzo->ncarte--;
            mazzo->testa=(mazzo->testa+1)%52;}}

void lasciacarta(int idcarta,int*mano,s_mazzo*mazzo){ // questa funzione lascia la carta "idcarta" dalla mano in fondo al mazzo
    mazzo->carta[(mazzo->testa+mazzo->ncarte)%52]=mano[idcarta]; // deposita la carta in fondo al mazzo
    mano[idcarta]=-1; // la rimuove dalla mano
    mazzo->ncarte++;}

char semecarta(int carta){ // restituisce il codice ascii del simbolo "cuore", "quadri", "fiori" o "picche"
    return 3+carta/13;} // a seconda della carta che riceve come parametro

char valorecarta(int carta){ // restituisce l'ascii del valore O il numero
    switch (carta%13){
        case 0: return 'A';   // se la carta è un asso o una figura restituisce il codice ascii della lettera
        case 10: return 'J'; // corrispondente
        case 11: return 'Q';
        case 12: return 'K';
        default: return carta%13;}} // altrimenti restituisce un intero da 0 a 9

/* Per decidere chi ha la mano migliore ho deciso di assegnare a ogni mano un punteggio da 769 (per un poker di assi)
   in giù. La combinazione di carte vale 100 punti: 700 per il poker, 600 per il colore, 500 per il full, 400 per la scala,
   300 per il tris, 200 per la doppia coppia, 100 per la coppia. La carta più alta della combinazione inoltre vale da 5 a
   65 punti (dal 2 all'asso), e il suo seme vale da 1 a 4. In questo modo ogni mano ha un punteggio unico diverso da quello
   degli altri giocatori, e posso capire chi ha vinto semplicemente confrontando i punteggi. Esempio: scala con J di cuori
   come carta più alta = 400+50+4 = 454 punti
*/

int puntipervalore(int carta){ // restituisce i punti per valore della carta indicata
    carta=carta%13;
    if (carta==0) return 65;
    else return carta*5;}

int puntiperseme(int carta){ // restituisce i punti per seme della carta indicata
    return 4-carta/13;}

int puntimano(int*mano){ // calcola i punti della mano
    int i,j,min,tmp;
    for (i=0;i<4;i++){ // questo ciclo ordina le carte per valore (asso a destra)
        for (j=i+1;j<5;j++)
            if (j==i+1||puntipervalore(mano[min])>puntipervalore(mano[j])) min=j;
        if (puntipervalore(mano[min])<puntipervalore(mano[i])){
            tmp=mano[min];
            mano[min]=mano[i];
            mano[i]=tmp;}}
    //controllo poker
    // le carte sono in ordine, quindi mi basta controllare se la prima è uguale alla penultima o la seconda all'ultima
    if (mano[0]%13==mano[3]%13||mano[1]%13==mano[4]%13)
        return 704+puntipervalore(mano[1]);
    // controllo colore
    if (mano[0]/13==mano[1]/13&&mano[1]/13==mano[2]/13&&mano[2]/13==mano[3]/13&&mano[3]/13==mano[4]/13){
        tmp=0;
        return 600+puntiperseme(mano[0])+tmp;}
    // controllo full
    // casi possibili: AABBB, AAABB
    min=-1;
    if (mano[0]%13==mano[1]%13&&mano[2]%13==mano[4]%13) min=2; //AABBB
    if (mano[0]%13==mano[2]%13&&mano[3]%13==mano[4]%13) min=0; //AAABB
    if (min!=-1){
        for (i=min;i<min+3;i++)
            if (tmp<puntiperseme(mano[i]))
                tmp=puntiperseme(mano[i]);
        return 500+tmp+puntipervalore(mano[2]);}
    //controllo scala
    min=0;
    for (i=0;i<5;i++) if ((1+mano[i]%13)%13==mano[(i+1)%5]%13) min++;
    if (min==4){
        j=tmp=0;
        for(i=0;i<5;i++)
            if (j<puntipervalore(mano[i])){
                j=puntipervalore(mano[i]);
                tmp=puntiperseme(mano[i]);}
        return 400+j+tmp;}
    // controllo tris
    // casi possibili: AAA??,?AAA?,??AAA
    min=-1;
    for (i=0;i<3&&min==-1;i++) if (mano[i]%13==mano[i+2]%13) min=i;
    if (min!=-1){
        tmp=0;
        for(i=min;i<3;i++) if (tmp<puntiperseme(mano[i])) tmp=puntiperseme(mano[i]);
        return 300+tmp+puntipervalore(mano[min]);}
    // controllo doppia coppia e coppia
    min=tmp=-1;
    for (i=0;i<4;i++) // ciclo che cerca le coppie
        if (mano[i]%13==mano[i+1]%13){
            if (min!=-1) tmp=min;
            min=i;}
    if (tmp!=-1){// doppia coppia
        if (puntipervalore(mano[min])>puntipervalore(mano[tmp])) j=min;
        else j=tmp;
        if (puntiperseme(mano[j])>puntiperseme(mano[j+1])) return 200+puntipervalore(mano[j])+puntiperseme(mano[j]);
        else return 200+puntipervalore(mano[j])+puntiperseme(mano[j+1]);}
    if (min!=-1){ // coppia
        if (puntiperseme(mano[min])>puntiperseme(mano[min+1])) return 100+puntipervalore(mano[min])+puntiperseme(mano[min]);
        else return 100+puntipervalore(mano[min])+puntiperseme(mano[min+1]);}
    if (mano[0]%13==0) return 65+puntiperseme(mano[0]);
    else return puntipervalore(mano[4])+puntiperseme(mano[4]);}

void printbilanci(player*giocatori,int nplayers,int piatto){ // questa funzione stampa i bilanci
    int i;
    printf("Piatto: %d$\n",piatto);
    for (i=0;i<nplayers;i++)
        if (giocatori[i].stato!=-1) printf("%s: %d$\n",giocatori[i].nome,giocatori[i].bilancio);
    printf("\n");}

void printmano(int*mano){ // questa funzione stampa una serie di caratteri a formare la mano del giocatore
    int i;
    char seme,valore;
    // Istruzioni per la prima riga:
    putchar(ch_tl);
    for (i=0;i<4;i++) printf("%c%c%c",ch_o,ch_o,ch_tm);
    for (i=0;i<6;i++) putchar(ch_o);
    printf("%c\n",ch_tr);
    // Seguono le istruzioni per la seconda riga (valori)
    for (i=0;i<5;i++){
        valore=valorecarta(mano[i]);
        if (valore<10) printf("%c%-2d",ch_v,valore+1);
        else printf("%c%c ",ch_v,valore);}
    if (valore<10) printf("  %2d%c\n",valore+1,ch_v);
    else printf("   %c%c\n",valore,ch_v);
    // Seguono le istruzioni per la terza riga (semi)
    for (i=0;i<5;i++) {
        seme=semecarta(mano[i]);
        printf("%c%c ",ch_v,seme);}
    printf("   %c%c\n",seme,ch_v);
    // Seguono le istruzioni per l'ultima riga
    putchar(ch_bl);
    for (i=0;i<4;i++) printf("%c%c%c",ch_o,ch_o,ch_bm);
    for (i=0;i<6;i++) putchar(ch_o);
    printf("%c\n",ch_br);}

int ningioco(player*giocatori,int nplayers){
    int i=0,j=0;
    for(;i<nplayers;i++)if(giocatori[i].stato==1)j++;
    return j;}

int main(){
    system("chcp 65001"); // Questo comando mi consente di stampare caratteri unicode (WINDOWS!!!)
    srand(time(NULL)); // Uso il tempo corrente come seed per il generatore randomico
    int nplayers=4,humanplayers,bilanciobase=250,i,j,idmazziere=0,piatto=0,ultimapuntata=0,rilancio=0,choice,winner;
    s_mazzo mazzo;
    player*giocatori;
    player*curplayer;
    creamazzo(&mazzo); // creo il mazzo
    int cartescelte[5];
    char ch;
    do{ // Ciclo per la scelta del numero di giocatori
        system("cls");
        printf("Questo programma simula una partita a poker.\nUsa i tasti [+] e [-] per selezionare le opzioni, [invio] per confermare.\n");
        printf("Quanti giocatori devono partecipare? Questo numero comprende sia i giocatori umani che quelli controllati dal computer. %c %d %s\n",nplayers>2?'-':' ',nplayers,nplayers<6?"+":"");
        do ch=getch();
        while (ch!='+'&&ch!='-'&&ch!=13);
        if (ch=='+'&&nplayers<6) nplayers++;
        if (ch=='-'&&nplayers>2) nplayers--;}
    while (ch!=13);
    giocatori=(player*)malloc(nplayers*sizeof(player)); // alloco spazio per i giocatori richiesti
    if (giocatori==NULL){
        printf("Errore! Memoria insufficiente.");
        getch();
        return 0;}
    humanplayers=nplayers/2;
    do{ // Ciclo per la scelta di giocatori umani e controllati dal computer
        system("cls");
        printf("Quanti giocatori devono essere controllati dal computer e quanti umani? (+ e - per modificare)\n");
        if(humanplayers>0)printf("%d uman%c",humanplayers,humanplayers>1?'i':'o');
        if(humanplayers>0&&humanplayers<nplayers)printf(" e ");
        if(humanplayers<nplayers)printf("%d controllati dal computer",nplayers-humanplayers);
        do ch=getch();
        while (ch!='+'&&ch!='-'&&ch!=13);
        if (ch=='+'&&humanplayers<nplayers) humanplayers++;
        if (ch=='-'&&humanplayers>0) humanplayers--;}
    while (ch!=13);
    do{ // Ciclo per la scelta del budget iniziale
        system("cls");
        printf("Tutti i giocatori partono con la stessa somma di denaro, chi arriva a 0 perde.\n");
        printf("Con quale somma devono partire i giocatori?\n%c%d%s",bilanciobase>50?'-':' ',bilanciobase,bilanciobase<1000?"+\n":"\n");
        do ch=getch();
        while (ch!='+'&&ch!='-'&&ch!=13);
        if (ch=='+'&&bilanciobase<1000) bilanciobase+=50;
        if (ch=='-'&&bilanciobase>50) bilanciobase-=50;}
    while (ch!=13);
    for (i=0;i<nplayers;i++){
        do{ // Ciclo per la scelta dei nomi dei giocatori
            printf("Come si chiama il giocatore %d? (%s, max 20 caratteri)\n",i+1,i<humanplayers?"umano":"controllato dal computer");
            fgets(giocatori[i].nome,21,stdin);
            if (giocatori[i].nome[strlen(giocatori[i].nome)-1]=='\n') giocatori[i].nome[strlen(giocatori[i].nome)-1]='\0';
            giocatori[i].nome[0]=toupper(giocatori[i].nome[0]);}
        while (strlen(giocatori[i].nome)==0);
        giocatori[i].bilancio=bilanciobase;
        giocatori[i].stato=1;
        if(i<humanplayers)giocatori[i].ishuman=1;
        else giocatori[i].ishuman=0;
        for (j=0;j<5;j++) giocatori[i].mano[j]=-1;}
    do{ // ciclo della partita
        system("cls");
        printf("Il mazziere per questa mano e' %s\n",giocatori[idmazziere].nome);
        mescolamazzo(&mazzo); // mescolo il mazzo
        printf("Il mazziere mescola il mazzo e distribuisce le carte...\n");
        for (i=0;i<nplayers;i++) // vengono date le carte per ogni giocatore attivo
            if (giocatori[(idmazziere+i)%nplayers].stato!=-1){
                daicarte(giocatori[(idmazziere+i)%nplayers].mano,&mazzo);
                giocatori[(idmazziere+i)%nplayers].bilancio-=5;
                piatto+=5;}
        printf("Ogni giocatore lascia sul piatto 5$\n\nInizia la mano!\n");
        getch();
        for (i=0;i<nplayers;i++){ // Ciclo per ogni giocatore
            if (ningioco(giocatori,nplayers)==1){
                system("cls");
                printf("Solo un giocatore e' rimasto in gioco...\n");}
            else{
                curplayer=giocatori+((idmazziere+i)%nplayers);
                if(curplayer->stato==1){
                    system("cls");
                    printbilanci(giocatori,nplayers,piatto);
                    if (curplayer->ishuman){ // Se il giocatore è umano
                        if (curplayer->bilancio==0){ // se non ha soldi viene "spento" per il turno
                            printf("E' il tuo turno %s! Ma non hai piu' soldi per puntare... Non ti resta che lasciare.",curplayer->nome);
                            getch();
                            curplayer->stato=0;}
                        else{
                            printf("E' il tuo turno %s! Premi un tasto per guardare le tue carte...\n",curplayer->nome);
                            getch();
                            choice=0;
                            for (j=0;j<5;j++) cartescelte[j]=0;
                            do{ // ciclo per scegliere se vedere o passare (e quante carte cambiare se non si esce)
                                system("cls");
                                printf("Se desideri cambiare le tue carte selezionale ora (premi i tasti indicati sotto le carte, massimo 4).\n");
                                printf(" %c  %c  %c  %c     %c\n",cartescelte[0]?'X':' ',cartescelte[1]?'X':' ',cartescelte[2]?'X':' ',cartescelte[3]?'X':' ',cartescelte[4]?'X':' ');
                                printmano(curplayer->mano);
                                printf(" 1  2  3  4     5\n\n %c ",choice==0?'>':' ');
                                if(cartescelte[0]||cartescelte[1]||cartescelte[2]||cartescelte[3]||cartescelte[4])printf("Cambia le carte e fai %s\n %c Lascia\n",curplayer->bilancio>ultimapuntata?"la tua puntata":"all in",choice==1?'>':' ');
                                else printf("%s\n %c Lascia\n",curplayer->bilancio>ultimapuntata?"Fai la tua puntata":"All in",choice==1?'>':' ');
                                do ch=getch();
                                while (strchr("+-12345",ch)==NULL&&ch!=13);
                                if (ch=='+'||ch=='-') choice=!choice;
                                if (strchr("12345",ch)!=NULL){
                                    cartescelte[ch-49]=!cartescelte[ch-49];
                                    if (cartescelte[0]&&cartescelte[1]&&cartescelte[2]&&cartescelte[3]&&cartescelte[4])
                                        cartescelte[ch-49]=!cartescelte[ch-49];}}
                            while (ch!=13);
                            if (choice)curplayer->stato=0;
                            else { // vengono sostituite le carte richieste
                                for (j=0;j<5;j++)
                                    if (cartescelte[j])
                                        lasciacarta(j,curplayer->mano,&mazzo);
                                daicarte(curplayer->mano,&mazzo);
                                if (curplayer->bilancio<ultimapuntata){ // se vuoi puntare ma hai poco denaro metti tutto
                                    printf("Metti tutti i tuoi soldi nel piatto... Premi un tasto e buona fortuna!\n");
                                    getch();
                                    piatto+=curplayer->bilancio;
                                    curplayer->bilancio=0;}
                                else { // altrimenti hai facoltà di scelta
                                    if (ultimapuntata==0) curplayer->puntata=1; // la puntata minima è 1
                                    else curplayer->puntata=ultimapuntata; // o la precedente puntata (se presente)
                                    do{ // ciclo per scegliere quanto puntare
                                        system("cls");
                                        printf("Scegli quanto puntare. (Suggerimento: tieni premuto i tasti [+] e [-] per aumentare o diminuire rapidamente.\n");
                                        printmano(curplayer->mano);
                                        printf("Piatto: %d$\n%s %d$",piatto,ultimapuntata==0?"Punti":curplayer->puntata==ultimapuntata?"Vedi:":"Rilanci a",curplayer->puntata);
                                        printf("   (%s %c)\n",curplayer->puntata==ultimapuntata?"":"-",curplayer->puntata==curplayer->bilancio?'\b':'+');
                                        do ch=getch();
                                        while (ch!='+'&&ch!='-'&&ch!=13);
                                        if (ch=='+'&&curplayer->bilancio>curplayer->puntata) curplayer->puntata++;
                                        if (ch=='-'&&curplayer->puntata>ultimapuntata&&curplayer->puntata>1) curplayer->puntata--;}
                                    while (ch!=13);
                                    piatto+=curplayer->puntata;
                                    if (ultimapuntata!=0&&curplayer->puntata>ultimapuntata) rilancio=1;
                                    ultimapuntata=curplayer->puntata;
                                    curplayer->bilancio-=ultimapuntata;}}}}
                else{ // Se invece il giocatore corrente è controllato dal computer
                    printf("%s guarda le sue carte...\n",curplayer->nome);
                    curplayer->puntimano=puntimano(curplayer->mano);
                    j=0;
                    if (curplayer->puntimano<200){ // se ha una mano scarsa
                        j=rand()%5;
                        if (j==4){ // sceglie randomicamente se uscire (1/5 probabilità)
                            printf("%s lascia!\n",curplayer->nome);
                            curplayer->stato=0;}
                        else{ // o cambiare da 1 a 4 carte (equiprobabili)
                            printf("%s cambia %d cart%c.\n",curplayer->nome,j+1,j>0?'e':'a');
                            for(;j>=0;j--) lasciacarta(j,curplayer->mano,&mazzo);
                            daicarte(curplayer->mano,&mazzo);
                            curplayer->puntimano=puntimano(curplayer->mano);}}
                    if (curplayer->stato!=0){ // Se è ancora attivo
                        if (ultimapuntata==0){ // Se deve puntare lui
                            curplayer->puntata=10+rand()%10;
                            if (curplayer->bilancio>curplayer->puntimano*curplayer->puntata/100) //sceglie quanto puntare
                                curplayer->puntata=curplayer->puntimano*curplayer->puntata/100;
                            else curplayer->puntata=curplayer->bilancio;
                            ultimapuntata=curplayer->puntata;
                            piatto+=curplayer->puntata;
                            if(curplayer->puntata==curplayer->bilancio) printf("%s punta tutto quello che ha",curplayer->nome);
                            else printf("%s punta %d$",curplayer->nome,curplayer->puntata);
                            curplayer->bilancio-=curplayer->puntata;}
                        else{ // Altrimenti
                            if (curplayer->puntimano>400&&curplayer->bilancio>=2*ultimapuntata){ // Se ha una mano molto buona rilancia
                                curplayer->puntata=ultimapuntata*(10+rand()%10)/10;
                                ultimapuntata=curplayer->puntata;
                                rilancio=1;
                                printf("%s rilancia! La puntata cresce a %d$",curplayer->nome,ultimapuntata);}
                            else{ // altrimenti
                                if(j==0&&curplayer->puntimano<100&&curplayer->puntimano/15<ultimapuntata){
                                    printf("%s lascia!\n",curplayer->nome);
                                    curplayer->stato=0;}
                                else{
                                    if (ultimapuntata>curplayer->bilancio){ // se non ha abbastanza soldi mette tutto nel piatto
                                        printf("%s mette tutti i suoi soldi nel piatto.",curplayer->nome);
                                        curplayer->puntata=curplayer->bilancio;}
                                    else{ // altrimenti vede
                                        curplayer->puntata=ultimapuntata;
                                        printf("%s vede.",curplayer->nome);}}}
                            curplayer->bilancio-=curplayer->puntata;
                            piatto+=curplayer->puntata;}
                        printf(" (piatto: %d$)\n",piatto);}
                        getch();}}}}
        while(rilancio){ // Se qualcuno ha rilanciato viene eseguito il ciclo seguente
            rilancio=0;
            for (i=0;i<nplayers;i++){
                j=ningioco(giocatori,nplayers);
                curplayer=giocatori+(idmazziere+i)%nplayers;
                if(j==1){
                    system("cls");
                    printf("Solo un giocatore e' rimasto in gioco...\n");
                    getch();}
                if (j>1&&curplayer->stato==1&&curplayer->puntata<ultimapuntata){ // Se c'è più di un giocatore E è attivo E non in pari con la puntata
                    system("cls");
                    printbilanci(giocatori,nplayers,piatto);
                    if (curplayer->ishuman){ // Se è umano
                        if (curplayer->bilancio!=0){ // se ha ancora soldi
                            printf("Tocca a %s... Premi un tasto quando sei pronto a scegliere.",curplayer->nome);
                            getch();
                            choice=0;
                            do{ // ciclo per scegliere se vedere o lasciare
                                system("cls");
                                printf("Avevi puntato %d$, ma qualcuno ha rilanciato e ora devi mettere altri %d$ nel piatto.\n",curplayer->puntata,ultimapuntata-curplayer->puntata);
                                printf(" %c Lascia %s Vedi %s%c\n",choice==0?'>':' ',choice==0?"< ":" >",curplayer->bilancio>ultimapuntata-curplayer->puntata?"o rilancia ":"",choice==0?' ':'<');
                                do ch=getch();
                                while (ch!='+'&&ch!='-'&&ch!=13);
                                if (ch=='+'||ch=='-') choice=!choice;}
                            while (ch!=13);
                            if (choice){ // se vuoi vedere o rilanciare
                                if (curplayer->bilancio<ultimapuntata-curplayer->puntata){ // se non hai abbastanza soldi mette nel piatto tutto ciò che resta
                                    piatto+=curplayer->bilancio;
                                    curplayer->puntata+=curplayer->bilancio;
                                    curplayer->bilancio=0;
                                    printf("Metti tutto quello che ti resta nel piatto... Buona fortuna!\nOra il piatto ha %d$\n",piatto);
                                    getch();}
                                else{ // altrimenti
                                    if(curplayer->bilancio==ultimapuntata-curplayer->puntata){ // se puoi solo vedere
                                        curplayer->bilancio-=ultimapuntata-curplayer->puntata;
                                        piatto+=ultimapuntata-curplayer->puntata;
                                        printf("Metti nel piatto altri %d$, ora il piatto contiene %d$\n",ultimapuntata-curplayer->puntata,piatto);
                                        curplayer->puntata=ultimapuntata-curplayer->puntata;
                                        getch();}
                                    else{// se puoi anche rilanciare
                                        choice=ultimapuntata-curplayer->puntata;
                                        do{
                                            system("cls");
                                            printf("Devi scegliere se vedere o rilanciare...\n");
                                            printf("Metti nel piatto %d$ (%s%s%s)\n",choice,choice>ultimapuntata-curplayer->puntata?"-":"",(choice>ultimapuntata-curplayer->puntata&&choice<curplayer->bilancio)?" ":"",choice<curplayer->bilancio?"+":"");
                                            printf("%si...\n",choice>ultimapuntata-curplayer->puntata?"Rilanc":"Ved");
                                            do ch=getch();
                                            while(ch!='+'&&ch!='-'&&ch!=13);
                                            if(ch=='+'&&choice<curplayer->bilancio)choice++;
                                            if(ch=='-'&&choice>ultimapuntata-curplayer->puntata)choice--;}
                                        while(ch!=13);
                                        curplayer->bilancio-=choice;
                                        piatto+=choice;
                                        curplayer->puntata+=choice;
                                        if(curplayer->puntata>ultimapuntata){
                                            rilancio=1;
                                            ultimapuntata=curplayer->puntata;}}}}
                            else curplayer->stato=0;}
                        else{ // se infine ha 0$ nel bilancio esce
                            printf("Non hai abbastanza denaro, sei costretto a lasciare.\n");
                            giocatori[0].stato=0;
                            getch();}}
                    else { // Se invece il giocatore è controllato dal computer
                        if (curplayer->bilancio==0){ // Se non ha abbastanza denaro lascia
                            printf("%s non ha abbastanza denaro, lascia.\n",curplayer->nome);
                            curplayer->stato=0;}
                        else{ // altrimenti sceglie randomicamente
                            printf("%s deve scegliere se vedere o meno...\n",curplayer->nome);
                            if (rand()%2){ // nel 50% dei casi accetta
                                if (curplayer->bilancio>=ultimapuntata-curplayer->puntata){ // se ha abbastanza soldi li versa
                                    piatto+=ultimapuntata-curplayer->puntata;
                                    printf("%s vede, e deposita sul piatto i restanti %d$\nPiatto: %d$\n",curplayer->nome,ultimapuntata-curplayer->puntata,piatto);
                                    curplayer->bilancio=ultimapuntata-curplayer->puntata;
                                    curplayer->puntata=ultimapuntata;}
                                else { // altrimenti lascia tutto ciò che gli rimane
                                    piatto+=curplayer->bilancio;
                                    curplayer->puntata+=curplayer->bilancio;
                                    curplayer->bilancio=0;
                                    printf("%s mette nel piatto tutti i soldi che gli restano.\nPiatto: %d$\n",curplayer->nome,piatto);}}
                            else { // altrimenti rifiuta
                                printf("%s lascia.\n",curplayer->nome);
                                curplayer->stato=0;}}
                        getch();}}}}
        system("cls");
        printf("Piatto: %d$\nE' il momento di scoprire le carte...\n",piatto);
        winner=-1;
        j=0;
        for (i=0;i<nplayers;i++){ // per ogni giocatore
            curplayer=giocatori+(idmazziere+i)%nplayers;
            if (curplayer->stato==1){ // se è attivo
                j++;
                printf("\n%s scopre le sue carte:\n",curplayer->nome);
                curplayer->puntimano=puntimano(curplayer->mano); // calcola i punti
                printmano(curplayer->mano); // e stampa la mano
                if (winner==-1||giocatori[winner].puntimano<curplayer->puntimano)
                    winner=(idmazziere+i)%nplayers;}}
        if(j==1)printf("\n%s e' l'unico giocatore in gioco...\n",giocatori[winner].nome);
        else printf("\nSembra che %s abbia la mano migliore!\n",giocatori[winner].nome);
        printf("%s prende tutto il piatto.\n",giocatori[winner].nome);
        giocatori[winner].bilancio+=piatto; // assegna il piatto al vincitore
        piatto=ultimapuntata=0;
        for (i=0;i<nplayers;i++){
            if (giocatori[i].stato!=-1){
                if (giocatori[i].bilancio<=0) { // chi ha il bilancio nullo viene eliminato
                    printf("%s eliminato.\n",giocatori[i].nome);
                    giocatori[i].stato=-1;}
                else{ // gli altri lasciano le carte nel mazzo
                    giocatori[i].stato=1;
                    for (j=0;j<5;j++) lasciacarta(j,giocatori[i].mano,&mazzo);
                    giocatori[i].puntata=0;}}}
        do idmazziere=(idmazziere+1)%nplayers; // il mazziere diventa il successivo giocatore non eliminato
        while (giocatori[idmazziere].stato==-1);
        j=0;
        curplayer=NULL;
        for(i=0;i<nplayers;i++) // infine conta i giocatori rimasti
            if (giocatori[i].stato==1){
                j++;
                curplayer=giocatori+i;}
        if (j==1) printf("%s vince!\nFine partita.\n",curplayer->nome); // elogia l'ultimo rimasto
        getch();}
    while(j!=1); // o ripeti, se resta più di un giocatore
    free(giocatori);
    return 1;
}
