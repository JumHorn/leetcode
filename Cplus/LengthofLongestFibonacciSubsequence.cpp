#include<vector>
#include<list>
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
        int res=2;
        list<vector<int> > v;
	 	vector<int> tmp(3);
		tmp[0]=A[0];
		tmp[1]=A[1];
        tmp[2]=2;
		v.push_back(tmp);
		list<vector<int> >::iterator iter=v.begin();
		iter++;
		for(int i=2;i<A.size();i++)
		{
			for(iter++;iter!=v.end();iter++)
			{
				if(A[i]==(*iter)[0]+(*iter)[1])
				{
					(*iter)[0]=(*iter)[1];
					(*iter)[1]=A[i];
					(*iter)[2]++;
                    if((*iter)[2]>res)
                        res=(*iter)[2];
				}
			}
			for(int j=0;j<i;j++)
			{
				tmp[0]=A[j];
				tmp[1]=A[i];
				tmp[2]=2;
				v.push_back(tmp);
			}
		}
		return res==2?0:res;
    }
};
