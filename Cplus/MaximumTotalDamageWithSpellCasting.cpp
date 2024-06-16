#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maximumTotalDamage(vector<int> &power)
	{
		map<int, int> m; //{val,count}
		for (auto n : power)
			++m[n];
		long long cast0 = 0, ncast0 = 0, val0 = -10, cast1 = 0, ncast1 = 0, val1 = -5; //{cast,not cast,val}
		for (auto [val, count] : m)
		{
			long long cast = (long long)val * count, ncast = max(cast1, ncast1);
			if (val - val1 > 2)
				cast = max(cast, max(cast1, ncast1) + (long long)val * count);
			else if (val - val0 > 2)
				cast = max(cast, ncast1 + (long long)val * count);
			else
				cast = max(cast, ncast0 + (long long)val * count);

			cast0 = cast1;
			ncast0 = ncast1;
			val0 = val1;

			cast1 = cast;
			ncast1 = ncast;
			val1 = val;
		}
		return max(cast1, ncast1);
	}
};