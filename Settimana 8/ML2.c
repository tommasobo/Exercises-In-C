#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void usage()
{
    printf("Usage: searchstring <char> <string>\n");
    exit(1);

}

int main(int argc, char **argv)
{
    char c, *s;

    if (argc != 3) {
        usage();
    }

    if (strlen(argv[1] != 1)) {
        usage();
    }

    c = argv[1][0];
    s = argv[2];

    printf("C = %c", c);
    printf("S = %s", s);

    return 0;
}

