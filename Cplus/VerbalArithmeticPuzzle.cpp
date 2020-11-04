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
		int len = result.size();
		for (int i = index; i <= 7; ++i)
		{
			int tmp = 0;
			bool flag = false;
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
				tmp += digit[word[n - i - 1] - 'A'];
				flag = true;
			}
			if (i >= (int)result.size())
			{
				if (flag)
					return false;
				break;
			}
			tmp += carry;
			carry = tmp / 10;
			tmp %= 10;
			if (digit[result[len - i - 1] - 'A'] == -1)
			{
				if (used[tmp] != -1)
					return false;
				digit[result[len - i - 1] - 'A'] = tmp;
				used[tmp] = 0;
				if (backTracking(words, result, digit, used, i + 1, carry))
					return true;
				used[tmp] = -1;
				digit[result[len - i - 1] - 'A'] = -1;
			}
			if (digit[result[len - i - 1] - 'A'] != tmp)
				return false;
		}
		for (auto &word : words)
		{
			if (digit[word[0] - 'A'] == 0)
				return false;
		}
		if (digit[result[0] - 'A'] == 0)
			return false;
		return carry == 0;
	}
};