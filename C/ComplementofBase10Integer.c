
int bitwiseComplement(int N){
	if(N==0)
		return 1;
    unsigned int n=N,i=30,reverse=3;
	while(--i>0)
	{
		if(n&(1<<i))
			break;
		reverse=((reverse<<1)|1);
	}
	n^=reverse<<(i+1);
	return ~n;
}
