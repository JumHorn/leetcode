

int comp(int* map,int* wordmap)
{
	for(int i=0;i<26;i++)
		if(map[i]<wordmap[i])
			return 0;
	return 1;
}

int countCharacters(char ** words, int wordsSize, char * chars){
	int map[26]={0},res=0;
	while(*chars)
		map[*chars++-'a']++;
	for(int i=0;i<wordsSize;i++)
	{
		int wordmap[26]={0},len=0;
		char *p=words[i];
		while(*p)
		{
			len++;
			wordmap[*p++-'a']++;
		}
		if(comp(map,wordmap))
			res+=len;
	}
	return res;
}
