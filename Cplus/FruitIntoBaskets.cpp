#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int totalFruit(vector<int> &tree)
	{
		vector<pair<int, int>> count;
		int a = tree[0], b = 0;
		for (auto t : tree)
		{
			if (t == a)
				b++;
			else
			{
				count.push_back({a, b});
				b = 1;
				a = t;
			}
		}
		count.push_back({a, b});
		if (count.size() <= 1)
			return count[0].second;
		a = count[0].first, b = count[1].first;
		int res = count[0].second + count[1].second;
		int tmp = res;
		for (int i = 2; i < (int)count.size(); i++)
		{
			if (count[i].first == a)
				tmp += count[i].second;
			else if (count[i].first == b)
				tmp += count[i].second;
			else
			{
				res = max(res, tmp);
				tmp = count[i].second + count[i - 1].second;
				a = count[i].first;
				b = count[i - 1].first;
			}
		}
		res = max(res, tmp);
		return res;
	}
};