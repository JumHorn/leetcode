#include<vector>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
		vector<int> freq(40001);
		for(int i=0;i<(int)A.size();i++)
			++freq[A[i]];		
		int res=0;
		for(int i=0;i<40000;i++)
		{
			if(freq[i]>1)
			{
				res+=freq[i]-1;
				freq[i+1]+=freq[i]-1;
			}
		}
		res+=(freq[40000]-1)*freq[40000]/2;
		return res;
    }
};
