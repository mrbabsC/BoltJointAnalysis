#include <stdio.h>

int jointstiffness(int x, int y)
{
	int boltload = 0;
	int prel = 0;
	float stiffratio = 0.25;

	prel = stiffratio * x;
	boltload = y + prel;

	return  boltload;
}