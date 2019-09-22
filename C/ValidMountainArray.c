

bool validMountainArray(int* A, int ASize){
	if(ASize<3)
		return false;
	int i=1;
	while(i<ASize&&A[i-1]<A[i])
		i++;
	if(i==1||i==ASize||A[i-1]==A[i])
		return false;
	while(i<ASize&&A[i]<A[i-1])
		i++;
	return i==ASize;
}



