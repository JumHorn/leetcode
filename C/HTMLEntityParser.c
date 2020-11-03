#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

//if matched return replace length otherwise return 0
int doParser(char *text, int index, int *top)
{
	char *entity[] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
	char characters[] = {'\"', '\'', '&', '>', '<', '/'};
	for (int i = 0; i < ARRAY_SIZE(entity); ++i)
	{
		int len = strlen(entity[i]);
		if (strncmp(&text[index], entity[i], len) == 0)
		{
			text[*top] = characters[i];
			return len;
		}
	}
	return 0;
}

char *entityParser(char *text)
{
	int top = -1;
	for (int i = 0; text[i]; ++i)
	{
		text[++top] = text[i];
		if (text[i] == '&')
		{
			int len = doParser(text, i, &top);
			i += len == 0 ? 0 : len - 1;
		}
	}
	text[top + 1] = '\0';
	return text;
}