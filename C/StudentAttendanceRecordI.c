#include <stdbool.h>
#include <string.h>

bool checkRecord(char* s)
{
	int absent = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == 'A')
			++absent;
	}
	return absent <= 1 && !strstr(s, "LLL");
}
