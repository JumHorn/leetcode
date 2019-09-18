#include<vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
		int res=0;
		for(int i=0;i<=(int)A.size()-K;i++)
		{
			if(A[i]==0)
			{
				res++;
				for(int j=i;j<i+K;j++)
					A[j]=1-A[j];
			}
		}
		for(int i=0;i<K;i++)
			if(A[A.size()-i-1]==0)
				return -1;
		return res;	
    }
};