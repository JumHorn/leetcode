#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int uniqueLetterString(string s)
	{
		if (s.empty())
			return 0;
		int N = s.length();
		vector<int> left(N), right(N);
		int map[26] = {0};
		for (int i = 0; i < N; i++)
		{
			left[i] = i - map[s[i] - 'A'] + 1;
			map[s[i] - 'A'] = i + 1;
		}
		for (int i = 0; i < 26; i++)
			map[i] = N - 1;
		for (int i = N - 1; i >= 0; --i)
		{
			right[i] = map[s[i] - 'A'] - i + 1;
			map[s[i] - 'A'] = i - 1;
		}
		int res = 0;
		for (int i = 0; i < N; i++)
			res = (res + left[i] * right[i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};