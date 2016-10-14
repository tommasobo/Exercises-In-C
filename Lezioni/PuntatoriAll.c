#include <stdio.h>

int main()
{
	int var, *punt;
	
	var = 2;
	punt = &var;
	
	printf("Valore contenuto all'indirizzo di memoria %p o %p: %d",(void*)punt, (void*)&var, *punt);
	
	return 0;
}
