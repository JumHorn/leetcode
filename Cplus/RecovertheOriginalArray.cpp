#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> recoverArray(vector<int> &nums)
	{
		multiset<int> s(nums.begin(), nums.end());
		int smallest = *s.begin();
		for (auto it = ++s.begin(); it != s.end(); ++it)
		{
			int k = (*it - smallest) / 2; //try each possible k
			if (k > 0 && smallest + k == *it - k)
			{
				auto dup = s;
				vector<int> res;
				while (!dup.empty())
				{
					auto it0 = dup.begin();
					int n = *it0;
					dup.erase(it0);
					auto it1 = dup.find(n + 2 * k);
					if (it1 == dup.end())
						break;
					dup.erase(it1);
					res.push_back(n + k);
				}
				if (dup.empty())
					return res;
			}
		}
		return {};
	}
};

int main()
{
	vector<int> v = {2, 10, 6, 4, 8, 12};
	Solution().recoverArray(v);
	return 0;
}