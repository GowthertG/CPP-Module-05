#include <stdlib.h>
#include <stdio.h>
int main ()
{
	char *date_birth;
    date_birth = malloc(sizeof(char ) * 4);
	scanf("%s", date_birth);
    int date_birth_int = atoi(date_birth);
    printf ("%d", (2023 - date_birth_int));
}
