#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int flipgame(vector<int>& fronts, vector<int>& backs)
	{
		set<int> s, prune;
		for (int i = 0; i < (int)fronts.size(); i++)
		{
			if (fronts[i] == backs[i])
			{
				prune.insert(fronts[i]);
				s.erase(fronts[i]);
			}
			else
			{
				if (prune.find(fronts[i]) == prune.end())
					s.insert(fronts[i]);
				if (prune.find(backs[i]) == prune.end())
					s.insert(backs[i]);
			}
		}
		return s.empty() ? 0 : *s.begin();
	}
};
