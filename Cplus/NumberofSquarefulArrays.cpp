#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
 		return numSquarefulPerms(A,0);
    }

	int numSquarefulPerms(vector<int>& A,int index)
	{
		if(index==(int)A.size())
			return 1;
		int res=0;
        unordered_set<int> visited;
		for(int i=index;i<(int)A.size();i++)
		{
			if(index==0||isSquare((long)A[index-1]+(long)A[i]))
			{
                if(visited.find(A[i])==visited.end())
                {
                    visited.insert(A[i]);
                    swap(A[index],A[i]);
                    res+=numSquarefulPerms(A,index+1);
                    swap(A[index],A[i]);
                }
			}
		}
		return res;
	}

	bool isSquare(long n)
	{
		long hi=n,lo=0;
		while(lo<hi)
		{
			long mi=(hi-lo)/2+lo;
			if(mi*mi<n)
				lo=mi+1;
			else
				hi=mi;
		}
		return lo*lo==n;
	}
};