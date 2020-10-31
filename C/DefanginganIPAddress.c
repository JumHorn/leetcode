#include <stdio.h>
#include <string.h>

char *defangIPaddr(char *address)
{
	char *subaddr[4], **p = subaddr;
	for (char *token = strtok(address, "."); token; token = strtok(NULL, "."))
		*p++ = token;
	char *res = (char *)malloc(sizeof(char) * 25);
	sprintf(res, "%s[.]%s[.]%s[.]%s", subaddr[0], subaddr[1], subaddr[2], subaddr[3]);
	return res;
}