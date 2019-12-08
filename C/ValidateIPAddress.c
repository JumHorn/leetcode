#include <ctype.h>
#include <stdlib.h>

int checkIPversion(char *s)
{
	int count = 0;
	while (*s)
	{
		if (*s == '.')
			return 4;
		if (*s == ':')
			return 6;
		count++;
		if (count >= 5)
			break;
		++s;
	}
	return -1;
}

bool checkV4(char *IP)
{
	int size = 0;
	char *walker = IP, *runner = IP;
	while (*runner)
	{
		if (runner - walker > 3)
			return false;
		if (*runner != '.' && (*runner < '0' || *runner > '9'))
			return false;
		if (*runner == '.')
		{
			if (walker == runner)
				return false;
			*runner = '\0';
			int tmp = atoi(walker);
			if (tmp < 0 || tmp > 255)
				return false;
			if (runner - walker > 1 && *walker == '0')
				return false;
			size++;
			walker = ++runner;
			if (size > 3)
				return false;
		}
		else
			++runner;
	}
	if (walker == runner)
		return false;
	int tmp = atoi(walker);
	if (tmp < 0 || tmp > 255)
		return false;
	if (runner - walker > 1 && *walker == '0')
		return false;
	return size == 3;
}

bool checkV6(char *IP)
{
	int size = 0;
	char *walker = IP, *runner = IP;
	while (*runner)
	{
		if (runner - walker > 4)
			return false;
		*runner = toupper(*runner);
		if (*runner != ':' && ((*runner < '0' || *runner > '9') && (*runner < 'A' || *runner > 'F')))
			return false;
		if (*runner == ':')
		{
			if (walker == runner)
				return false;
			size++;
			walker = ++runner;
			if (size > 7)
				return false;
		}
		else
			++runner;
	}
	return walker != runner && runner - walker <= 4 && size == 7;
}

char *validIPAddress(char *IP)
{
	int ip = checkIPversion(IP);
	if (ip == 4)
	{
		if (checkV4(IP))
			return "IPv4";
	}
	else if (ip == 6)
	{
		if (checkV6(IP))
			return "IPv6";
	}
	return "Neither";
}