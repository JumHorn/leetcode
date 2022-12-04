#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long dividePlayers(vector<int> &skill)
	{
		sort(skill.begin(), skill.end());
		long long res = 0, N = skill.size(), sum = skill[0] + skill[N - 1];
		for (int i = 0, j = N - 1; i < j; ++i, --j)
		{
			if (skill[i] + skill[j] != sum)
				return -1;
			res += skill[i] * skill[j];
		}
		return res;
	}
};