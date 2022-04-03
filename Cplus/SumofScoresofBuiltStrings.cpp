#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
using namespace std;

// z_function

class Solution
{
public:
	vector<int> z_function(const string &s)
	{
		int N = s.length(), start = 0; //max length prefix at start
		vector<int> z(N);
		for (int i = 1; i < N; ++i)
		{
			if (start + z[start] > i)
				z[i] = min(z[i - start], start + z[start] - i);
			while (i + z[i] < N && s[i + z[i]] == s[z[i]])
				++z[i];
			if (start + z[start] < i + z[i])
				start = i;
		}
		z[0] = N;
		return z;
	}

	long long sumScores(string s)
	{
		auto z = z_function(s);
		return accumulate(z.begin(), z.end(), 0LL);
	}
};