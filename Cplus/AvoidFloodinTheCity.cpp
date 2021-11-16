#include <set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> avoidFlood(vector<int> &rains)
	{
		int N = rains.size();
		vector<int> res(N);
		set<int> s;						  //index
		unordered_map<int, int> fulllake; //{lake,index}
		for (int i = 0; i < N; ++i)
		{
			if (rains[i] == 0)
			{
				res[i] = 1;
				s.insert(i);
			}
			else
			{
				res[i] = -1;
				auto it = fulllake.find(rains[i]);
				if (it != fulllake.end())
				{
					auto iter = s.lower_bound(it->second);
					if (iter == s.end())
						return {};
					res[*iter] = rains[i];
					s.erase(iter);
				}
				fulllake[rains[i]] = i;
			}
		}
		return res;
	}
};