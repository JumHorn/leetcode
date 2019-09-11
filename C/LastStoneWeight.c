
#define swap(a,b) if((a)!=(b)) (a)^=(b)^=(a)^=(b)


void pushheap(int* stones,int hole)
{
    int val=stones[hole];
    for(;hole>0&&stones[(hole-1)/2]<val;hole=(hole-1)/2)
        stones[hole]=stones[(hole-1)/2];
    stones[hole]=val;
}

void popheap(int* stones,int last)
{
	int val=stones[0],hole=0,index=2*0+2;
    for(;index<last;index=index*2+2)
    {
        if(stones[index-1]>stones[index])
            index--;
        stones[(index-1)/2]=stones[index];
        hole=index;
    }
    if(index==last)
    {
        stones[(index-1)/2]=stones[index-1];
        hole=index-1;
    }
    stones[hole]=stones[last];
    stones[last]=val;
    pushheap(stones,hole);
}

void makeheap(int* stones,int end)
{
	for(int i=1;i<end;i++)
		pushheap(stones,i);
}

int lastStoneWeight(int* stones, int stonesSize){
	makeheap(stones,stonesSize);
	int x,y;
	while(stonesSize>=2)
	{
		stonesSize--;
		popheap(stones,stonesSize);
		x=stones[stonesSize];
		stonesSize--;
		popheap(stones,stonesSize);
		y=stones[stonesSize];
		x-=y;
		if(x!=0)
		{
			stones[stonesSize]=x;
			pushheap(stones,stonesSize);
			stonesSize++;
		}
	}
	if(stonesSize==0)
		return 0;
	return stones[0];
}