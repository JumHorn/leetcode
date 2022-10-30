#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	struct info
	{
		string id;
		int pop;
		long long sum;
		info(){};

		info(string i, int p, long long s)
		{
			id = i;
			pop = p;
			sum = s;
		};
	};
	vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
	{
		unordered_map<string, info> m; //{creator,info}
		long long pop = 0;
		int N = views.size();
		for (int i = 0; i < N; ++i)
		{
			auto it = m.find(creators[i]);
			if (it != m.end())
			{
				it->second.sum += views[i];
				pop = max(pop, it->second.sum);
				if (it->second.pop < views[i])
				{
					it->second.pop = views[i];
					it->second.id = ids[i];
				}
				else if (it->second.pop == views[i] && it->second.id > ids[i])
					it->second.id = ids[i];
			}
			else
			{
				m[creators[i]] = info(ids[i], views[i], views[i]);
				pop = max(pop, (long long)views[i]);
			}
		}
		vector<vector<string>> res;
		for (auto &p : m)
		{
			if (p.second.sum == pop)
				res.push_back({p.first, p.second.id});
		}
		return res;
	}
};