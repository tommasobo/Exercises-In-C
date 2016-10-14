#include <stdlib.h>
#include <stdio.h>
#include <windows.h>    //se avete un OS che non sia Windows, cancellate questo include e tutti gli sleep nel codice
#define N 20
#define M 20
#define CLS system("cls")

int funzione(int l, int j);

int matrix[N][M];
int matrixSeconda[N][M];

int main()
{

int i = 0, k = 0, h = 0;
int numeroVite, contatore = 0;

printf("Utente, quante vite vuoi inserire?\n");
scanf("%d", &numeroVite);

funzione(i, k);

while(numeroVite >= 0)
{
i = rand() % 21; //assegno i e k casuali dove andrÚ a mettere gli 1
k = rand() % 21;
matrix[i][k] = 1;
numeroVite--; //continuo il ciclo fino a quando non vengono inserite tutte le vite
}
/*i = 3;
k = 3;
matrix[i][k] = 1;
i = 4;
k = 3; Controllo sull’effettivo funzionamento del programma, per vedere come si comportava nel caso di 3 celle vive vicine.
matrix[i][k] = 1;
i = 5;
k = 3;
matrix[i][k] = 1;*/
for(i = 0; i < N; i++)
{
puts("");
for(k = 0; k < M; k++)
{
printf("% d", matrix[i][k]);
}
}

while(1) //Inizia un ciclo infinito che stamper‡ in continuazione le due matrici costantemente aggiornate.
{
Sleep(1000); //pausa di 1 secondo
for(i = 1; i < N; i++) //sia la i che la k le faccio partire da 1 cosÏ da considerare solo la parte interna della matrice, per cui tutte le celle che si
//troveranno nella "cornice" si annulleranno.
{
for(k = 1; k < M; k++)
{
contatore = 0; //contatore ci permette di tenere il conto di quante celle vive vicine sono state rilevate.
if(matrix[i][k] == 1)
{
if(matrix[i][k - 1] == 1) //serie di if che considerano tutte le singole opzioni della vicinanza di una cella viva
contatore = contatore + 1;
if(matrix[i - 1][k - 1] == 1)
contatore = contatore + 1;
if(matrix[i - 1][k] == 1)
contatore = contatore + 1;
if(matrix[i - 1][k + 1] == 1)
contatore = contatore + 1;
if(matrix[i][k + 1] == 1)
contatore = contatore + 1;
if(matrix[i + 1][k + 1] == 1)
contatore = contatore + 1;
if(matrix[i + 1][k] == 1)
contatore = contatore + 1;
if(matrix[i + 1][k - 1] == 1)
contatore = contatore + 1;

if((contatore == 2 || contatore == 3) && matrix[i][k] == 1) //se sono state rilevate 2 o 3 celle vive vicine ad una cella viva, allora essa sopravvive.
matrixSeconda[i][k] = 1;
if((contatore < 2 || contatore > 3) && matrix[i][k] == 1) //in caso contrario, muore.
matrixSeconda[i][k] = 0;

}
else if(matrix[i][k] == 0) //consideriamo ora l’ipotesi per cui la cella che consideriamo sia morta
{
if(matrix[i][k - 1] == 1) //serie di if identica alla precedente
contatore++;
if(matrix[i - 1][k - 1] == 1)
contatore++;
if(matrix[i - 1][k] == 1)
contatore++;
if(matrix[i - 1][k + 1] == 1)
contatore++;
if(matrix[i][k + 1] == 1)
contatore++;
if(matrix[i + 1][k + 1] == 1)
contatore++;
if(matrix[i + 1][k] == 1)
contatore++;
if(matrix[i + 1][k - 1] == 1)
contatore++;

if(contatore == 3) //a questo punto, se ci sono 3 celle vive vicine allora la cella nasce
matrixSeconda[i][k] = 1; //i cambiamenti li applichiamo sempre alla seconda matrice
if(contatore != 3) //in caso contrario, resta morta
matrixSeconda[i][k] = 0;
}
}

}
int conta = 0;
puts("\n");
for(i = 0; i < N; i++)
{
puts("");
for(k = 0; k < M; k++)
{
    if (matrixSeconda[i][k]==1)
        conta++;
printf("% d", matrixSeconda[i][k]); //stampiamo i cambiamenti applicati alla seconda matrice
}
}
printf("\n\nVivi: %d", conta);
Sleep(1);
puts("\n");
for( i = 0; i < N; i++)
{
for(k = 0; k < M; k++)
{
matrix[i][k] = matrixSeconda[i][k];
/*In pratica, ho analizzato tutte le celle ed applicato i cambiamenti ad una matrice identica alla principale. DopodichÈ copio la seconda matrice sulla prima
e tutti i cambiamenti, di conseguenza, vengono copiati in quest’ultima. CosÏ posso ripetere tutto il programma sfruttando la prima matrice ed applicando tutti
i cambiamenti su quella di supporto.*/
}
}

}

system("pause");
return 0;

}

int funzione(int l, int j)
{
for(l = 0; l < N; l++)
{
for(j = 0; j < M; j++)
{
matrix[l][j] = 0;
matrixSeconda[l][j] = 0;
}
}

return 0;
}
