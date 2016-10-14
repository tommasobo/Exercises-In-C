
#include <stdio.h>

int main()
{
    FILE *mioFile;

    mioFile = fopen("cazzo.txt","w");
    fprintf(mioFile, "Test");

    return 0;
}
