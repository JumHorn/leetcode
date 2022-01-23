#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isSolvable(vector<string> &words, string result)
	{
		vector<int> digit(26, -1), used(10, -1);
		for (auto &word : words)
		{
			if (word.length() > result.length())
				return false;
		}
		return backTracking(words, result, digit, used, 0, 0);
	}

	bool backTracking(vector<string> &words, string &result, vector<int> &digit, vector<int> &used, int index, int carry)
	{
		int N = result.size();
		for (int i = index; i < N; ++i)
		{
			int sum = 0;
			for (auto &word : words)
			{
				int n = word.size();
				if (i >= n)
					continue;
				if (digit[word[n - i - 1] - 'A'] == -1)
				{
					for (int j = 0; j < 10; ++j)
					{
						if (used[j] == -1)
						{
							digit[word[n - i - 1] - 'A'] = j;
							used[j] = 0;
							if (backTracking(words, result, digit, used, i, carry))
								return true;
							used[j] = -1;
							digit[word[n - i - 1] - 'A'] = -1;
						}
					}
					return false;
				}
				sum += digit[word[n - i - 1] - 'A'];
			}
			sum += carry;
			carry = sum / 10;
			sum %= 10;
			if (digit[result[N - i - 1] - 'A'] == -1)
			{
				if (used[sum] != -1)
					return false;
				digit[result[N - i - 1] - 'A'] = sum;
				used[sum] = 0;
				if (backTracking(words, result, digit, used, i + 1, carry))
					return true;
				used[sum] = -1;
				digit[result[N - i - 1] - 'A'] = -1;
			}
			if (digit[result[N - i - 1] - 'A'] != sum)
				return false;
		}
		//prefix zero check
		for (auto &word : words)
		{
			if (word.length() > 1 && digit[word[0] - 'A'] == 0)
				return false;
		}
		if (result.length() > 1 && digit[result[0] - 'A'] == 0)
			return false;
		return carry == 0;
	}
};