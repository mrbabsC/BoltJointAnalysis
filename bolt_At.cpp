#include <stdio.h>

float bolt_At(int boltsize)
{
	float m = 0;
	switch (boltsize)
	{
	case 5:
		m = 14.2;
		break;
	case 6:
		m = 20.1;
		break;
	case 7:
		m = 28.9;
		break;
	case 8:
		m = 36.6;
		break;
	case 10:
		m = 58.0;
		break;
	case 12:
		m = 84.3;
		break;
	case 14:
		m = 115.0;
		break;
	case 16:
		m = 157.0;
		break;
	case 18:
		m = 192.0;
		break;
	case 20:
		m = 245.0;
		break;
	case 22:
		m = 303.0;
		break;
	case 24:
		m = 353.0;
		break;
	case 27:
		m = 459.0;
		break;
	case 30:
		m = 561.0;
		break;
	case 33:
		m = 694.0;
		break;
	case 36:
		m = 817.0;
		break;
	case 39:
		m = 976.0;
		break;
	default:
		printf("Bolt size N/A\n");
		return 0;
	}
	return m;
}