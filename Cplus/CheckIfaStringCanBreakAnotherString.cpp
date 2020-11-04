#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool checkIfCanBreak(string s1, string s2)
	{
		vector<int> hash1(26), hash2(26);
		for (auto c : s1)
			++hash1[c - 'a'];
		for (auto c : s2)
			++hash2[c - 'a'];
		return fullSmall(hash1, hash2) || fullSmall(hash2, hash1);
	}

	bool fullSmall(vector<int> &v1, vector<int> &v2)
	{
		int N = v1.size(), sum1 = 0, sum2 = 0;
		for (int i = 0; i < N; ++i)
		{
			sum1 += v1[i];
			sum2 += v2[i];
			if (sum1 > sum2)
				return false;
		}
		return true;
	}
};