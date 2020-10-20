#include <stdbool.h>

#define HEAD0 128 //(1<<7)
#define HEAD1 192 //(1<<7)|(1<<6)
#define HEAD2 224 //(1<<7)|(1<<6)|(1<<5)
#define HEAD3 240 //(1<<7)|(1<<6)|(1<<5)|(1<<4)
#define HEAD4 248 //(1<<7)|(1<<6)|(1<<5)|(1<<4)|(1<<3)

bool validUtf8(int *data, int dataSize)
{
	int i = 0, len = 0;
	while (i < dataSize)
	{
		if ((data[i] & HEAD0) == 0)
			len = 1;
		else if ((data[i] & HEAD2) == HEAD1)
			len = 2;
		else if ((data[i] & HEAD3) == HEAD2)
			len = 3;
		else if ((data[i] & HEAD4) == HEAD3)
			len = 4;
		else
			return false;
		if (len + i > dataSize)
			return false;
		for (int j = i + 1; j < len + i; j++)
			if ((data[j] & HEAD1) != HEAD0)
				return false;
		i += len;
	}
	return true;
}