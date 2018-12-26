#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int res=0;
		int index=0;
		for(int j=0;j<A.size();j++)
		{
			if(A[j]>A[index])
				index=j;
            int tmp=isValid(L,R,A[index]);
			res+=tmp;
            int partmax=index;
			for(int i=1;i<=j;i++)
			{
                if(tmp==0)
                {
                    i=partmax;
                    tmp=1;
                    continue;
                }
				if(i-1==partmax)
				{
					partmax=maxIndex(A,i,j);
                    tmp=isValid(L,R,A[partmax]);
                }
				res+=tmp;
			}
		}
		return res;
    }

	int isValid(int L,int R,int val)
	{
		if(val<=R&&val>=L)
			return 1;
		else
			return 0;
	}

	int maxIndex(vector<int>& A,int i,int j)
	{
		int res=i++;
		while(i<=j)
        {
			if(A[i]>A[res])
				res=i;
            i++;
        }
		return res;
	}
};
