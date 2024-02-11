#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxPalindromesAfterOperations(vector<string> &words)
	{
		vector<int> count(26), len;
		for (auto &word : words)
		{
			for (auto c : word)
				++count[c - 'a'];
			len.push_back(word.size());
		}
		int odd = 0, even = 0;
		for (auto n : count)
		{
			even += n;
			if (n % 2 == 1)
			{
				odd += n % 2;
				even -= 1;
			}
		}
		int res = 0;
		sort(len.begin(), len.end());
		for (auto n : len)
		{
			if (n % 2 == 1)
			{
				if (odd > 0)
					--odd;
				else
				{
					++odd;
					even -= 2;
				}
			}
			n = n - n % 2;
			if (even < n)
				break;
			even -= n;
			++res;
		}

		return res;
	}
};