#include<stdlib.h>
#include<string.h>

bool comp(char* lhs,char* rhs,int* hash)
{
	while(*lhs&&*rhs)
	{
		if(*lhs!=*rhs)
			return hash[*lhs-'a']<hash[*rhs-'a'];
		lhs++;
		rhs++;
	}
	if(*rhs)
		return true;
	return false;
}

bool isAlienSorted(char ** words, int wordsSize, char * order){
	int *hash=(int*)malloc(sizeof(int)*26);
	int i=0;
	while(*order)
		hash[*order++-'a']=i++;
	for(int i=0;i<wordsSize-1;i++)
		if(!comp(words[i],words[i+1],hash))
			return false;
	return true;
}

