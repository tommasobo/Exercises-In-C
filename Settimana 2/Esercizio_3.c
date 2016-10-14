/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> //Utilizzo la libreria math.h per utilizzare la funzione math.h
#define PI 3.14 //Dichiaro la costante PI per utilizzare successivamente nel calcolo dell'area del cerchio

int main()
{
    float d, AreaQuadrato, AreaCerchio, AreaTriangolo; // Dichiaro le variabili che utilizzerò. In questo caso sono di tipo reale considerando i possibili risultati

    printf("Inserisci un numero reale D: ");
    scanf("%g",&d); // Utilizzo la funzione scanf per memorizzare il numero che verrà inserito dall'utente

    AreaQuadrato = d*d; //Calcolo l'area del quadrato
    printf("\nL\'area del quadrato di lato D e\': %g\n",AreaQuadrato);

    AreaCerchio = PI * (d/2) * (d/2); //Calcolo l'area del cerchio usando la costante PI
    printf("L'area del cerchio di diametro D e\': %g\n",AreaCerchio);

    AreaTriangolo = (d*d)*(sqrt(3)/4); //Utilizzo la funzione sqrt presente nella libreria math.h per calcolare la radice quadrata e successivamente calcolo l'area del triangolo
    printf("L'area del triangolo equilatero di lato D e\': %g\n\n",AreaTriangolo);

    system("pause"); // Compatibile solo con Windows

    return 0;
}
