#include <stdio.h>

int main()
{
    FILE *test;

    test = fopen("test", "w");
    if (test == NULL) {
        fprintf(stderr,"Errore del cazzo");
    }

    return 0;
}
