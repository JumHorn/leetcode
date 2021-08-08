#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long maxProduct(string s)
	{
		//manacher
		s.insert(s.begin(), '$');
		int N = s.length();
		vector<int> radius = manacher(s);
		vector<int> prefix(N), suffix(N);
		for (int i = 1; i < N; ++i)
		{
			prefix[i + radius[i] - 1] = max(prefix[i + radius[i] - 1], 2 * radius[i] - 1);
			suffix[i - radius[i] + 1] = max(suffix[i - radius[i] + 1], 2 * radius[i] - 1);
		}
		// 最长palindrome不全用的情况下
		for (int i = 1; i < N; ++i)
			suffix[i] = max(suffix[i], suffix[i - 1] - 2);
		for (int i = N - 2; i >= 0; --i)
			prefix[i] = max(prefix[i], prefix[i + 1] - 2);

		for (int i = 1; i < N; ++i)
			prefix[i] = max(prefix[i], prefix[i - 1]);
		for (int i = N - 2; i >= 0; --i)
			suffix[i] = max(suffix[i + 1], suffix[i]);

		long long res = 0;
		for (int i = 0; i < N - 1; ++i)
			res = max(res, (long long)prefix[i] * suffix[i + 1]);
		return res;
	}

	vector<int> manacher(string &s)
	{
		int N = s.length();
		vector<int> radius(N, 1);
		int center = 1;	   //the center of the right most radius
		int maxradius = 1; //the right most pos of the right most radius can reach
		for (int i = 2; i < N; ++i)
		{
			if (i < maxradius)
				radius[i] = min(radius[2 * center - i], maxradius - i);
			while (s[i + radius[i]] == s[i - radius[i]]) ////with the added $,out of range avoided
				++radius[i];

			if (radius[i] + i > maxradius) //change center and the maxradius
			{
				maxradius = radius[i] + i;
				center = i;
			}
		}
		return radius;
	}
};