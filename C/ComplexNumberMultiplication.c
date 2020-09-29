#include <stdio.h>
#include <stdlib.h>

char* complexNumberMultiply(char* a, char* b)
{
	int m1, n1, m2, n2;
	sscanf(a, "%d+%di", &m1, &n1);
	sscanf(b, "%d+%di", &m2, &n2);
	int m = m1 * m2 - n1 * n2;
	int n = m1 * n2 + m2 * n1;
	char* res = (char*)malloc(sizeof(char) * 20);
	sprintf(res, "%d+%di", m, n);
	return res;
}
