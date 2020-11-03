
#define max(a, b) (((a) > (b)) ? (a) : (b))

int minNumberOfFrogs(char *croakOfFrogs)
{
	int index[26] = {0}, state[5] = {0};
	char *croak = "croak";
	for (int i = 0; croak[i]; ++i)
		index[croak[i] - 'a'] = i;
	int frog = 0, res = 0;
	for (int i = 0; croakOfFrogs[i]; ++i)
	{
		char c = croakOfFrogs[i];
		if (c != 'c' && --state[index[c - 'a'] - 1] < 0)
			return -1;
		++state[index[c - 'a']];
		if (c == 'c')
			++frog;
		else if (c == 'k')
			--frog;
		res = max(res, frog);
	}
	return frog == 0 ? res : -1;
}