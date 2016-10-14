#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NONE -1

int *search(char c, char *s);

void usage()
{
    printf("Usage: searchstring <char> <string>\n");
    exit(1);

}

int main(int argc, char **argv)
{
    char c, *s;
    int *index, i, n;

    if (argc != 3) {
        usage();
    }

    if (strlen(argv[1]) != 1) {
        usage();
    }

    c = argv[1][0];
    s = argv[2];

    index = search(c,s);
    printf("Il carattere %c è presente nella stringa %s nelle seguenti posizioni: ", c, s);
    n = strlen(s);
    for (i = 0; i < n && index[i] != NONE; i++)
        printf("%d", index[i]);
    printf("\n");

    printf("C = %c\n", c);
    printf("S = %s\n\n", s);

    return 0;
}

int *search(char c, char *s)
{
    int *trovato = (int*) malloc (strlen(s) * sizeof(int)), i, j = 0, n;

    if (trovato == NULL)
        return NULL;

    for (i=0; i < n; i++)
        trovato[i] = NONE;

    for (i = 0; i < n; i++)
        if (s[i] == c)
            trovato[j++] = i;

}
