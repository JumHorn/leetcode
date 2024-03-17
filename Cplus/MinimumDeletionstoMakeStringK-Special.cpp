#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDeletions(string word, int k)
	{
		int N = word.size(), res = N, sum = 0;
		vector<int> count(26);
		for (auto c : word)
			++count[c - 'a'];
		sort(count.begin(), count.end());
		for (int i = 0; i < 26; ++i)
		{
			sum = 0;
			for (int j = i; j < 26; ++j)
				sum += min(count[j], count[i] + k);
			res = min(res, N - sum);
		}
		return res;
	}
};