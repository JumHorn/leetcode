#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int partitionDisjoint(vector<int>& A) {
		int i=0;
		int right=getIndex(A,i);
		int rightvalue=A[i];
		if(right<=i)
		{
			return i+1;
		}
		for(int j=i+1;j<=right;j++)
		{
			int tmp=getIndex(A,j);
			if(tmp>right)
			{
				right=tmp;
				rightvalue=A[j];
			}
			else if(A[j]==rightvalue)
				right++;
			if(right==(int)A.size())
				return right+1;
		}
		return 0;
	}

	int getIndex(vector<int>& arr,int start)
	{
		int res=0;
		for(int i=0;i<(int)arr.size();i++)
			if(arr[start]>arr[i])
				res++;
		return res;
	}
};
