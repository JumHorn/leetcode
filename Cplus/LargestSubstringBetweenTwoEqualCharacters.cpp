#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxLengthBetweenEqualCharacters(string s)
	{
		int N = s.length();
		vector<int> first(26, -1), last(26);
		for (int i = 0; i < N; ++i)
		{
			int index = s[i] - 'a';
			if (first[index] == -1)
				first[index] = i;
			last[index] = i;
		}
		int res = 0;
		for (int i = 0; i < 26; ++i)
		{
			if (first[i] != -1 && last[i] - first[i] > res)
				res = last[i] - first[i];
		}
		return res - 1;
	}
};