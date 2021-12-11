#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> goodDaysToRobBank(vector<int> &security, int time)
	{
		vector<int> prefix, suffix;
		int N = security.size();
		prefix.push_back(1);
		int val = security[0];
		for (int i = 1; i < N; ++i)
		{
			if (security[i] <= val)
				prefix.push_back(prefix.back() + 1);
			else
				prefix.push_back(1);
			val = security[i];
		}
		val = security[N - 1];
		suffix.push_back(1);
		for (int i = N - 2; i >= 0; --i)
		{
			if (security[i] <= val)
				suffix.push_back(suffix.back() + 1);
			else
				suffix.push_back(1);
			val = security[i];
		}
		reverse(suffix.begin(), suffix.end());

		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			if (prefix[i] - 1 >= time && suffix[i] - 1 >= time)
				res.push_back(i);
		}
		return res;
	}
};