

int numMatchingSubseq(char* S, char** words, int wordsSize)
{
	char* hash[128][wordsSize];
	int hashSize[128] = {0};
	for (int i = 0; i < wordsSize; ++i)
		hash[(int)words[i][0]][hashSize[(int)words[i][0]]++] = words[i];
	for (int i = 0; S[i]; ++i)
	{
		int size = hashSize[(int)S[i]];
		hashSize[(int)S[i]] = 0;
		for (int j = 0; j < size; ++j)
		{
			char* p = ++hash[(int)S[i]][j];
			hash[(int)*p][hashSize[(int)*p]++] = p;
		}
	}
	return hashSize[0];  //count number of char '\0'
}
