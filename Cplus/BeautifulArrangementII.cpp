#include <cmath>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> constructArray(int n, int k)
	{
		unordered_set<int> s;
		vector<int> seen(n + 1), res(n);
		for (int i = 1; i <= n; i++)
		{
			seen[i] = 1;
			res[0] = i;
			s.clear();
			if (backTrace(res, seen, s, 1, i, n, k))
				break;
			seen[i] = 0;
		}
		return res;
	}

	bool backTrace(vector<int> &res, vector<int> &seen, unordered_set<int> &s, int index, int num, int n, int k)
	{
		if ((int)s.size() > k)
			return false;
		if (index == n)
			return (int)s.size() == k;
		for (int i = 1; i <= n; i++)
		{
			if (seen[i] == 1)
				continue;
			seen[i] = 1;
			s.insert(abs(i - num));
			res[index] = i;
			if (backTrace(res, seen, s, index + 1, i, n, k))
				return true;
			s.erase(abs(i - num));
			seen[i] = 0;
		}
		return false;
	}
};

int main()
{
	Solution sol;
	sol.constructArray(3, 2);
	return 0;
}