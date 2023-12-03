#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countCompleteSubstrings(string word, int k)
	{
		// DSU
		int N = word.size(), res = 0;
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || abs(word[i] - word[i - 1]) > 2)
			{
				res += countSubseq(word, j, i, k);
				j = i;
			}
		}
		return res;
	}

	int countSubseq(string &word, int left, int right, int k)
	{
		int res = 0, len = right - left;
		for (int i = 1; i <= 26 && i * k <= len; ++i)
			res += countSubseq(word, left, right, i * k, k);
		return res;
	}

	// [left, right)
	int countSubseq(string &word, int left, int right, int window, int k)
	{
		int res = 0;
		vector<int> count(26);
		for (int i = left; i < window + left; ++i)
			++count[word[i] - 'a'];
		if (exactlyK(count, k))
			++res;
		for (int i = window + left; i < right; ++i)
		{
			++count[word[i] - 'a'];
			--count[word[i - window] - 'a'];
			if (exactlyK(count, k))
				++res;
		}
		return res;
	}

	bool exactlyK(vector<int> &count, int k)
	{
		for (auto n : count)
		{
			if (n != 0 && n != k)
				return false;
		}
		return true;
	}
};