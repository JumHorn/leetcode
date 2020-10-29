
int numJewelsInStones(char* J, char* S)
{
	int hash['z' - 'A' + 1] = {0};
	for (int i = 0; S[i]; ++i)
		++hash[S[i] - 'A'];
	int res = 0;
	for (int j = 0; J[j]; ++j)
		res += hash[J[j] - 'A'];
	return res;
}
