#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_params(int argcm, char *argv[]);

int main(int argc, char *argv[])
{
    int i;
    int sum = 0;

    if (argc < 2) {
        printf("Usage: sum <int> [<int> ...]\n");
        return 1;
    }

    if (check_params(argc, argv)) {
        for (i=0; i < argc; i++)
            sum += atoi(argv[i]);
        printf("Somma: %d\n\n", sum);
    } else {
        printf("Errore: parametro non valido\n\n");
        return 1;
    }



    return 0;
}

int check_params(int argc, char *argv[])
{
    int i;
    for (i = 1; i < argc; i++)
        if (atoi(argv[i]) == 0 && strcmp(argv[i], "0") != 0)
            return 0;
        return 1;


}






