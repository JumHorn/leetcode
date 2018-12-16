#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		vector<int> ugly(n,INT_MAX);
		vector<int> leastIndex(primes.size(),0);
		ugly[0]=1;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<primes.size();j++)
				ugly[i]=min(ugly[i],primes[j]*ugly[leastIndex[j]]);
			for(int j=0;j<primes.size();j++)
				leastIndex[j]+=(ugly[i]==primes[j]*ugly[leastIndex[j]]?1:0);
		}
		return ugly[n-1];
	}
};
