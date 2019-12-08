#include <stdlib.h>

//*********************************************************************
// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
//*********************************************************************

// Initializes an empty nested list and return a reference to the nested integer.
struct NestedInteger *NestedIntegerInit();

// Return true if this NestedInteger holds a single integer, rather than a nested list.
bool NestedIntegerIsInteger(struct NestedInteger *);

// Return the single integer that this NestedInteger holds, if it holds a single integer
// The result is undefined if this NestedInteger holds a nested list
int NestedIntegerGetInteger(struct NestedInteger *);

// Set this NestedInteger to hold a single integer.
void NestedIntegerSetInteger(struct NestedInteger *ni, int value);

// Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
void NestedIntegerAdd(struct NestedInteger *ni, struct NestedInteger *elem);

// Return the nested list that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
struct NestedInteger **NestedIntegerGetList(struct NestedInteger *);

// Return the nested list's size that this NestedInteger holds, if it holds a nested list
// The result is undefined if this NestedInteger holds a single integer
int NestedIntegerGetListSize(struct NestedInteger *);

struct NestedInteger *deserializezHelper(char **s)
{
	if (!**s)
		return NULL;
	struct NestedInteger *res = NestedIntegerInit();
	while (**s)
	{
		if (**s == '[')
		{
			++(*s);
			NestedIntegerAdd(res, deserializezHelper(s));
		}
		else
		{
			char *p = *s;
			while (*p && *p != ']' && *p != ',')
				++p;
			bool flag = false;
			if (*p && *p == ']')
				flag = true;
			if (*s != p)
			{
				char c = *p;
				*p = '\0';
				struct NestedInteger *tmp = NestedIntegerInit();
				NestedIntegerSetInteger(tmp, atoi(*s));
				NestedIntegerAdd(res, tmp);
				*p = c;
			}
			*s = p;
			if (**s)
			{
				++(*s);
				if (**s && **s == ',')
					++(*s);
			}
			if (flag)
				break;
		}
	}
	return res;
}

struct NestedInteger *deserialize(char *s)
{
	return *NestedIntegerGetList(deserializezHelper(&s));
}
