#include <string>
using namespace std;

class Solution
{
public:
	string sortString(string s)
	{
		int count[26] = {0};
		for (auto c : s)
			++count[c - 'a'];
		int N = s.length();
		string res(N, ' ');
		for (int i = 0; i < N;)
		{
			for (int j = 0; j < 26; ++j)
			{
				if (count[j] > 0)
				{
					--count[j];
					res[i++] = j + 'a';
				}
			}
			for (int j = 25; j >= 0; --j)
			{
				if (count[j] > 0)
				{
					--count[j];
					res[i++] = j + 'a';
				}
			}
		}
		return res;
	}
};