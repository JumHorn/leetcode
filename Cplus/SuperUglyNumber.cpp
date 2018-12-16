#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
		unordered_set<int> visited(primes.begin(),primes.end());
		int ugly=1;
		for(int i=1;i<n;i++)
		{
			ugly++;
			int j,tmp=ugly;
            if(visited.find(tmp)!=visited.end())
            {
                visited.insert(ugly);
                continue;
            }
			for(j=0;j<primes.size();j++)
			{
				if(tmp%primes[j]==0)
				{
					tmp=tmp/primes[j];
					if(visited.find(tmp)!=visited.end())
					{
						visited.insert(ugly);
						break;
					}
                    if(tmp==1)
                    {
						visited.insert(ugly);
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
