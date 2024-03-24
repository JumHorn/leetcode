#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> mostFrequentIDs(vector<int> &nums, vector<int> &freq)
	{
		map<long long, unordered_set<int>> m; //{freq,set of value}
		unordered_map<int, long long> fm;	  //{val,freq}
		int N = nums.size();
		vector<long long> res;
		for (int i = 0; i < N; ++i)
		{
			int n = nums[i], c = freq[i];
			long long f = fm[n];
			fm[n] += c;
			long long new_f = f + c;
			m[f].erase(n);
			if (m[f].empty())
				m.erase(f);
			m[new_f].insert(n);
			if (m.empty())
				res.push_back(0);
			else
			{
				auto it = --m.end();
				res.push_back(it->first);
			}
		}
		return res;
	}
};