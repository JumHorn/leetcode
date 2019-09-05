
bool Equiv(int** dominoes,int i,int j)
{
	return (dominoes[i][0]==dominoes[j][0]&&dominoes[i][1]==dominoes[j][1])
		|| (dominoes[i][0]==dominoes[j][1]&&dominoes[i][1]==dominoes[j][0]);
}

int numEquivDominoPairs(int** dominoes, int dominoesSize, int* dominoesColSize){
	int res=0;
	for(int i=0;i<dominoesSize-1;i++)
		for(int j=i+1;j<dominoesSize;j++)
		{
			if(Equiv(dominoes,i,j))
				res++;
		}
	return res;
}

