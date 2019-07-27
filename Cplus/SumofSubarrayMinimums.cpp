#include<vector>
using namespace std;

class Solution {
	static const int MOD = 1e9+7;
public:
    int sumSubarrayMins(vector<int>& A) {
		int l=1,r=1,res=0;
        while(r<(int)A.size()&&A[r]>=A[0])
            r++;
        res=(res+l*r*A[0]%MOD)%MOD;
		for(int i=1;i<(int)A.size();i++)
		{
            if(A[i-1]<=A[i])
            {
                l=1;
                r=1;
                while(i+r<(int)A.size()&&A[i+r]>=A[i])
                    r++;
            }
            else
            {
                l++;
                r=1;
                while(i-l>=0&&A[i-l]>A[i])
                    l++;
                while(i+r<(int)A.size()&&A[i+r]>=A[i])
                    r++;
            }
			res=(res+l*r*A[i]%MOD)%MOD;
		}
		return res;
    }
};