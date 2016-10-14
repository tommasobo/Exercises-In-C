/*
Autore: Tommaso Bonato
Numero matricola: 0000723575
E-Mail: tommaso.bonato@studio.unibo.it
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c = 126;  // Dichiaro le variabili e assegno loro un valore
    signed char sc = -126;
    unsigned char uc = 161;
    float f = 32.565;
    double d = 144.61454;
    long double ld = 1645343.54;
    int i = 44, contatore, contatore1;
    short int si = 2400;
    long int li = 45000;
    unsigned short int usi = 38000;
    unsigned int ui = 9000;
    unsigned long int uli = 500000;
    int x = 15; // Verrà utilizzato per visualizzare il corrispondente esadecimale
    int o = 33; // Verrà utilizzato per visualizzare il corrispondente numero ottale


    /* Al posto di usare due variabili distinte per contare i caratteri all'interno delle stringhe dei printf, si poteva usare un
       singolo printf usando il carattere \ per andare a capo e quindi una sola variabile "contatore" */

    contatore = printf("Il valore della variabile di tipo char considerata e\': %c\n",c);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(c));  //sizeof mi restituisce l'occupazione in memoria della variabile
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo signed char considerata e\': %c\n",sc);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(sc));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo unsigned char considerata e\': %c\n",uc);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(uc));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo float considerata e\': %f\n",f);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(f));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo double considerata e\': %f\n",d);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(d));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    /*contatore = printf("Il valore della variabile di tipo long double considerata e\': %e\n",ld);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(ld));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);
    Long Double non funziona correttamente a causa di un problema di compatibilità tra il compilatore MinGW e MSVC*/

    contatore = printf("Il valore della variabile di tipo int considerata e\': %d\n",i);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(i));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo short int considerata e\': %hd\n",si); // Utilizzo un modificatore lunghezza "h" davanti a un short int
    contatore1 = printf("La variabile considerata precedentemente occupa %hd byte\n",sizeof(si));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo long int considerata e\': %ld\n",li); // Utilizzo il modificatore lunghezza "l" davanti a un long int
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(li));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo unsigned short int considerata e\': %hd\n",usi); // Utilizzo un modificatore lunghezza "h" davanti a un unsigned short int
    contatore1 = printf("La variabile considerata precedentemente occupa %hd byte\n",sizeof(usi));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo unsigned int considerata e\': %d\n",ui);
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(ui));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    contatore = printf("Il valore della variabile di tipo unsigned long int considerata e\': %ld\n",uli); // Utilizzo il modificatore lunghezza "l" davanti a un unsigned long int
    contatore1 = printf("La variabile considerata precedentemente occupa %d byte\n",sizeof(uli));
    printf("Numero di caratteri contenuti nella due righe precedenti: %d\n\n",contatore+contatore1);

    // Successivamente utilizzo vari componenti del comando di conversione

    printf("Stampo la variabile di tipo int riservendo 5 spazi e allineando il contenuto a sinistra: %-5d\n",i); //Combinazione di modificatori e campo minimo
    printf("Eseguo la stessa cosa indicando il segno: %-+5d\n",i); //Combinazione di modificatori e campo minimo
    printf("Inserisco degli 0 negli spazi vuoti e lascio uno spazio prima della variabile: % 05d\n",i); //Combinazione di modificatori e campo minimo
    printf("Visualizzo solo 2 cifre dopo la virgola di un numero reale: %.2f\n",f); // Precisione dell'indicatore di conversione
    printf("Visualizzo solo 3 cifre significative di un numero reale: %.3g\n",f); //Precisione dell'indicatore di conversione
    printf("Stampo un numero esadecimale con il modificatore #: %#x\n",x); // Stampo un numero esadecimale usando il modificatore # che inserisce automaticamente "0x" davanti un numero esadecimale
    contatore = printf("Stampo un numero ottale con il modificatore #: %#o\n",o); // Stampo un numero ottale usando il modificatore # che inserisce automaticamente "0" davanti un numero ottale
    printf("Numero caratteri contenuti nella riga precedente: %d\n\n",contatore);

    system("pause"); // Compatibile solo con Windows

    return 0;


}
