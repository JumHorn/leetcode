#include <climits>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int flipgame(vector<int> &fronts, vector<int> &backs)
	{
		unordered_set<int> s;
		int res = INT_MAX, N = fronts.size();
		for (int i = 0; i < N; ++i)
		{
			if (fronts[i] == backs[i])
				s.insert(fronts[i]);
		}
		for (int i = 0; i < N; ++i)
		{
			if (s.find(fronts[i]) == s.end())
				res = min(res, fronts[i]);
			if (s.find(backs[i]) == s.end())
				res = min(res, backs[i]);
		}
		return res == INT_MAX ? 0 : res;
	}
};