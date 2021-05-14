#include "Inputs.h"

int GetInt (char msj[])
{
	int num;

	printf("%s", msj);
	scanf("%d", &num);

	return num;
}

float GetFloat (char msj[])
{
	float num;

	printf("%s", msj);
	scanf("%f", &num);

	return num;
}

char GetChar (char msj[])
{
	char letra;

	printf("%s", msj);
	fflush(stdin);
	scanf("%c", &letra);

	return letra;
}

void GetString(char *msj, char *value)
{
    printf(msj);
    fflush(stdin);
    scanf("%[^\n]", value);
}

