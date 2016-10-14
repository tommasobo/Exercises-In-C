#include <stdio.h>

int main()
{
    int v;
    char c;
    
    if (scanf("%d%c", &v,&c) == 1 && c == '\n') {
        printf("OK\n");
    } else {
        printf("Not an integer.\n");
    }
    return 0;
}
