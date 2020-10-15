#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minFlipsMonoIncr(string S)
	{
		int N = S.length(), res;
		vector<int> prefixsum(N + 1); //sum of '1'
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] += prefixsum[i] + S[i] - '0';
		if (prefixsum[N] == 0 || prefixsum[N] == N) //all '0' or all '1'
			return 0;
		res = prefixsum[N];
		for (int i = 0; i < N; ++i)
			res = min(res, prefixsum[i] + (N - i) - (prefixsum[N] - prefixsum[i]));
		return res;
	}
};