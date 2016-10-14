#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX(x, y) (x>y?x:y)

int *readlist(char *argv[], int n)
{
    int i, *list = (int *) malloc(n*sizeof(int));
    if (list == NULL)
        return NULL;
    for (i=1; i <=n; i++) {
        if ((list[i-1] = atoi(argv[i])) == 0 && strcmp(argv[i], "0") != 0) // La lista parte da 0 (i-1)
            return NULL;
    }
    return list;
}

int max_rec (int *list, int start, int end)
{
    int mid = (start+end)/2;
    int m1, m2;

    if (start == end)
        return list[start];

    m1 = max_rec(list,start,mid);
    m2 = max_rec(list,mid+1,end);
    return MAX(m1,m2);
}

int max_it(int *list, int n)
{
    int i, max=list[0];

    for (i=1; i < n; i++)
        max = MAX(list[i], max);
    return max;
}

int main(int argc, char *argv[]) // In argv[0] c'è il nome dell'eseguibile e quindi non va utilizzato
{
    int *list, n, max;
    unsigned long int start, end;

    n = argc - 1;
    if (argc < 2) {
        printf("Usage: max <int> [<int> ...]\n");
        return 1;
    }

    if ((list = readlist(argv, argc-1)) == NULL) {
        printf("Error: parameters are not integers as requested\n");
        return 1;
    }

    start = clock();
    max = max_rec(list, 0, n-1);
    end = clock();
    printf("MAX rec: %d, TIME: %g sec\n", max, (double)(start-end)/CLOCKS_PER_SEC);

    start = clock();
    max = max_it(list, n);
    end = clock();
    printf("MAX rec: %d, TIME: %g sec\n", max, (double)(start-end)/CLOCKS_PER_SEC);

    return 0;
}
