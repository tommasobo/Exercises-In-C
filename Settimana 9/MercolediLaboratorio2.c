#include <stdio.h>
#include <string.h>
#include <time.h>

int ispalindrome_rec(char *str, int start, int end)
{
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return ispalindrome_rec(str, start+1, end-1);
}

int ispalindrome_it(char *str, int n)
{
    int i;

    for (i = 0; i < n/2; i++)
        if (str[i] != str[n-1-i])
            return 0;
    return 1;
}

int main(int argc, char *argv[]) // In argv[0] c'è il nome dell'eseguibile e quindi non va utilizzato
{
    char *str;
    int check, n;
    unsigned long int start, end;

    if (argc != 2) {
        printf("Usage: palindrome <string>\n");
        return 1;
    }

    str = argv[1];
    n = strlen(str);

    start = clock();
    check = ispalindrome_rec(str, 0, n-1);
    end = clock();
    printf("PALINDROME rec: %s, TIME: %fsec\n", check == 0 ? "FALSE":"TRUE", (double)(end-start)/CLOCKS_PER_SEC);

    start = clock();
    check = ispalindrome_it(str, n);
    end = clock();
    printf("PALINDROME it: %s, TIME: %.10fsec\n", check == 0 ? "FALSE":"TRUE", (double)(end-start)/CLOCKS_PER_SEC);

    return 0;
    }
