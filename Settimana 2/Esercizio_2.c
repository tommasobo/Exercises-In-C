/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1,num2,numTemp; // Inizializzo due variabili intere. numTemp svolge lo stesso compito di TempResult ma utilizzo una variabile di tipo int che occupa meno memoria anche se fanno esattamente la stessa cosa
    float TempResult; // Inizializzo una variabili reale in cui salvare temporaneamente il risultato delle operazioni. Ho preferito utilizzare una variabile reali per il risultato ma per molti operazioni sarebbero bastate varabili intere

    printf("Inserisci due numeri interi separati da uno spazio: ");
    scanf("%d%d",&num1,&num2); // Utilizzo la funzione scanf per memorizzare i due numeri inseriti dall'utente in due variabili
    printf("Numero A = %d  |  Numero B = %d\n\n",num1,num2); // Stampo i due numeri memorizzati

    TempResult = num1 + num2; // Operatore somma
    printf("La loro somma e\': %g\n",TempResult);

    TempResult = num1 - num2; // Operatore sottrazione
    printf("La loro differenza e\': %g\n",TempResult);

    TempResult = num1 * num2; // Operatore moltiplicazione
    printf("Il loro prodotto e\': %g\n",TempResult);

    TempResult = (float) num1 / num2; // Operatore divisione utilizzando anche un operazione di casting
    printf("Il loro rapporto e\': %g\n",TempResult);

    TempResult = num1 / num2; // Operatore divisione. In questo caso tronca il risultato
    printf("Il quoziente e\': %g\n",TempResult);

    TempResult = num1 % num2; // Operatore modulo
    printf("Il resto della divisione e\': %g\n\n",TempResult);

    numTemp = num1; // Salvo temporaneamente il valore di num1 in una variabile in modo da lasciare inalterato il valore di num1
    numTemp += num2; // Questo operatore permette di eseguire la stessa cosa di numTemp = (numTemp + num2). La stessa cosa si può fare per la sottrazione
    printf("La loro somma utilizzando l'operatore a+=b e\': %d\n",numTemp);

    numTemp = num1; // Salvo temporaneamente il valore di num1 in una variabile in modo da lasciare inalterato il valore di num1
    numTemp -= num2; // Questo operatore permette di eseguire la stessa cosa di numTemp = (numTemp - num2).
    printf("La loro differenza l'operatore a-=b e\': %d\n",numTemp);

    numTemp = num1; // Riassegno a numTemp il valore di num1
    numTemp *= num2; // Questo operatore permette di eseguire la stessa cosa di numTemp = (numTemp * num2). La stessa cosa si può fare per la divisione.
    printf("Il loro prodotto utilizzando l'operatore a*=b e\': %d\n",numTemp);

    numTemp = num1; // Salvo temporaneamente il valore di num1 in una variabile in modo da lasciare inalterato il valore di num1
    numTemp /= num2; // Questo operatore permette di eseguire la stessa cosa di numTemp = (numTemp / num2).
    printf("Il quoziente utilizzando l'operatore a/=b e\': %d\n",numTemp);

    numTemp = num1; // Salvo temporaneamente il valore di num1 in una variabile in modo da lasciare inalterato il valore di num1
    numTemp %= num2; // Questo operatore permette di eseguire la stessa cosa di numTemp = (numTemp % num2).
    printf("Il resto utilizzando l'operatore a%%=b e\': %d\n\n",numTemp);

    TempResult = (num1*(num1/num2)+num1-num2*(5+num1)); // Combino i vari operatori per calcolare il risultato di un'espressione
    printf("Il risultato della seguente espressione [A*(A/B)+A-B*(5+A)] e\': %g\n",TempResult); // Dato che utilizzo numeri interi, le eventuali divisioni utilizzano solo il quoziente troncando eventuali numeri dopo la virgola

    TempResult = (num1/num2+((num1-num2)/3+(num1-num2))+10);
    printf("Il risultato della seguente espressione {A/B+[(A-B)/3+(A-B)]+10} e\': %g\n\n",TempResult);

    // L'operatore num1++ incrementa di un'unità l'operando dopo averne restituito il suo valore (incremento postfisso)
    // L'operatore ++num1 incrementa di un'unità l'operando prima che venga restituito il suo valore (incremento prefisso)
    // La stessa cosa vale per i decrementi postfissi e prefissi

    printf("Incremento postfisso di un\' unita\' al numero A: %d\n",num1++);
    printf("Incremento prefisso  di un\' unita\' al numero B: %d\n",++num2);
    printf("Incremento postfisso di un\' unita\' al numero A: %d\n",num1++);
    printf("Incremento prefisso  di un\' unita\' al numero B: %d\n",++num2);
    printf("Decremento postfisso di un\' unita\' al numero A: %d\n",num1--);
    printf("Decremento prefisso  di un\' unita\' al numero B: %d\n",--num2);
    printf("Decremento postfisso di un\' unita\' al numero A: %d\n",num1--);
    printf("Decremento prefisso  di un\' unita\' al numero B: %d\n\n",--num2);

    system("pause"); // Compatibile solo con Windows

    return 0;
}
