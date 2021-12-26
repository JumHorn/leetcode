#include <string>
using namespace std;

class Solution
{
public:
	string abbreviateProduct(int left, int right)
	{
		long long suff = 1, c = 0, max_suff = 1e12;
		double pref = 1.0;
		for (int i = left; i <= right; ++i)
		{
			pref *= i;
			while (pref >= 1e5)
				pref /= 10;
			suff *= i;
			while (suff % 10 == 0)
			{
				suff /= 10;
				++c;
			}
			suff %= max_suff;
		}
		auto s = to_string(suff);
		return (s.size() <= 10 ? s : to_string((int)pref) + "..." + s.substr(s.size() - 5)) + "e" + to_string(c);
	}
};