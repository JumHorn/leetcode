#include <stdbool.h>
#include <string.h>

bool isValid(char *code)
{
	int N = strlen(code), top = -1;
	if (N == 0 || code[0] != '<')
		return false;
	char *tag[1000];
	bool valid = false;
	for (int index = 0; index + 1 < N;)
	{
		if (code[index++] != '<')
			continue;
		valid = false;
		if (code[index] == '!') //comment tag
		{
			if (top == -1) //[CDATA[ must be wrapped in a tag
				return false;
			if (strncmp(code + index + 1, "[CDATA[", 7) != 0)
				return false;
			//jump to comment
			for (index += 8; index < N; ++index)
			{
				if (code[index] == ']' && strncmp(code + index, "]]>", 3) == 0)
					break;
			}
			index += 3;
		}
		else if (code[index] == '/') //finish tag
		{
			if (top == -1) //finish tag must be matched
				return false;
			++index;
			char *pos = strstr(code + index, ">");
			if (!*pos || strncmp(code + index, tag[top--], pos - code - index) != 0)
				return false;
			index += (pos - code - index) + 1;
			if (index < N && top == -1) //all string should be wrapped in one tag
				return false;
		}
		else //start tag
		{
			int tagSize = 0;
			for (int i = index; i < N && code[i] != '>'; ++i, ++tagSize)
			{
				if (code[i] > 'Z' || code[i] < 'A') //tag only consist of uppercase letters
					return false;
			}
			if (index + tagSize == N || tagSize < 1 || tagSize > 9)
				return false;
			tag[++top] = strndup(code + index, tagSize);
			index += tagSize + 1;
		}
		valid = true;
	}
	return valid && top == -1;
}