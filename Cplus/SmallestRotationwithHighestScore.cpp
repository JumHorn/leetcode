#include<vector>
using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& A) {
		int num=0,res=0;
		int n=A.size();
		for(int i=0;i<n;i++)
		{
			A[i]-=n-1;
			if(A[i]>=0)
				num++;
		}
		if(num==n)
			return 0;
		for(int i=0;i<n;i++)
		{
			int tmp=0;
			for(int j=0;j<n;j++)
			{
				if(j==i)
					A[j]-=n-1;
				else
					A[j]+=1;
				tmp+=(A[j]>=0?1:0);
			}
			if(tmp>num)
			{
				num=tmp;
				res=i+1;
			}
		}
		return res;
    }
};
