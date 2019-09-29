


int peakIndexInMountainArray(int* A, int ASize){
	for(int i=1;i<ASize-1;i++)
		if(A[i]>A[i-1]&&A[i]>A[i+1])
			return i;
	return -1;
}

