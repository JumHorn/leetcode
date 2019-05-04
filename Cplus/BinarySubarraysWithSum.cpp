#include<vector>
#include<unordered_map>
using namespace std;

/*
slide window
add all subarray which end with i,when i updated
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
		if(A.empty())
			return 0;
		int res=0;
		int i=-1,j=0,sum=0;
		while(++i<(int)A.size())
		{
			sum+=A[i];
			if(sum==S)
            {
				res++;
                for(int k=j;k<i;k++)
                {
                    if(A[k]==0)
                        res++;
                    else
                        break;
                }
            }
			else if(sum>S)
            {
                while(j<=i&&A[j]==0)
                    j++;
                j++;
                sum--;
                if(j<=i)
                    res++;
                for(int k=j;k<=i;k++)
                {
                    if(A[k]==0)
                        res++;
                    else
                        break;
                }
            }
		}
		return res;
    }
};

int main()
{
    //int a[]={1,0,1,0,1};
    vector<int> v(5);
    v[2]=1;
    Solution sol;
    sol.numSubarraysWithSum(v,0);
}