#include<vector>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		int ugly=1;
		for(int i=1;i<n;i++)
		{
			ugly++;
			int j,tmp=ugly;
			for(j=0;j<primes.size();j++)
			{
				if(tmp%primes[j]==0)
				{
					tmp=tmp/primes[j];
                    if(tmp==1)
                    {
                        break;
                    }
					j=-1;
				}
                else if(tmp<primes[j])
                {
                    i--;
                    break;
                }
			}
			if(j==primes.size())
				i--;
		}
		return ugly;
    }
};
