

int reachNumber(int target){
	int sum=0,i=1;
	if(target<0)
		target=-target;
	while(true)
	{
		sum+=i;
		if(sum==target)
			return i;
		if(sum>target)
			break;
		i++;
	}
	if((sum-target)%2==0)
		return i;
	return i+1+i%2;
}



