#include<vector>
using namespace std;
/*
[1,2,3,4,5,6,7,8]
dp[i]
i=3 3
i=4 3
i=5 4
i=6 4
i=7 4
i=8 5
*/

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        vector<vector<int> > v;
	 	vector<int> tmp(4);
		tmp[0]=A[0];
		tmp[1]=A[1];
		tmp[2]=tmp[0]+tmp[1];
        tmp[3]=2;
		v.push_back(tmp);
		for(int i=2;i<A.size();i++)
		{
			for(int j=0;j<v.size();j++)
			{
				if(A[i]==v[j][2])
				{
					v[j][0]=v[j][1];
					v[j][1]=v[j][2];
					v[j][2]=v[j][1]+v[j][0];
					v[j][3]++;
				}
			}
			for(int j=0;j<i;j++)
			{
				tmp[0]=A[j];
				tmp[1]=A[i];
				tmp[2]=tmp[0]+tmp[1];
				tmp[3]=2;
				v.push_back(tmp);
			}
		}
		int res=2;
		for(int i=0;i<v.size();i++)
		{
			if(v[i][3]>res)
				res=v[i][3];
		}
		return res==2?0:res;
    }
};
