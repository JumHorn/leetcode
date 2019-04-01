#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
		vector<int> B=A;        
		sort(B.begin(),B.end());
		unsigned long long sumA=0,sumB=0;
		for(int i=0;i<(int)A.size();i++)
		{
			sumA+=A[i];
			sumB+=B[i];
			if(sumA==sumB)
				return i+1;
		}
		return 0;
    }
};
