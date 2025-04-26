#include <stdio.h>

int calcboltpreload(float x, int y, float z)
{
	int preload = 0;

	preload = x * y * z;
	return preload;
}