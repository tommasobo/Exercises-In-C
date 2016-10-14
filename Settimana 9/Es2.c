#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 101

void invertiRicorsivamente (char* str) {

    char c = *str;

    if (c != '\0') {
            invertiRicorsivamente(str + 1);
        putchar(c);
    } }


void invertiIterativamente(char str[])
{
    int dim;
    int i;

    dim = strlen(str);
    printf("Versione iterativa: ");
    for (i=dim-1; i>=0; i--)
        printf("%c",str[i]); }

int main() {

    char str[MAX]; // Array di 101 char
    int dim;

    printf("Stringa da invertire (max 100 caratteri): ");
    gets(str);

    printf("\nVersione ricorsiva: ");
    invertiRicorsivamente(str); // Chiarmo la funzione invertiRicorsivamente
    printf("\n");
    invertiIterativamente(str); // Chiarmo la funzione invertiIterativamente

    printf("\n");

    return 0; }
