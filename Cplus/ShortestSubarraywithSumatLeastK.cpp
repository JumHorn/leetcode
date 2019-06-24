#include<algorithm>
#include<numeric>
#include<vector>
using namespace std;

class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
		for(int i=1;i<=(int)A.size();i++)
		{
			int sum=accumulate(A.begin(),A.begin()+i,0);
			if(sum>=K)
				return i;
			for(int j=0;j<(int)A.size()-i;j++)
			{
				sum=sum-A[j]+A[i+j];
				if(sum>=K)
					return i;
			}
		}
		return -1;
    }
};
