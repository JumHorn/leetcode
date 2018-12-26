#include<vector>
using namespace std;

//do not consider duplicate array like 2,2,2,2,2  
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
		int index=0,count=0,res=0;
		for(int i=0;i<A.size();i++)
		{
			if(A[i]>=L&&A[i]<=R)
			{
				count=i-index+1;
				res+=count;
			}
			else if(A[i]<L)
			{
				res+=count;
			}
			else
			{
				count=0;
				index=i+1;
			}
		}
		return res;
    }
};
