#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int compress(vector<char> &chars)
	{
		if (chars.empty())
			return 0;
		char pre = chars[0];
		int N = chars.size(), res = 0;
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || chars[i] != pre)
			{
				int count = i - j;
				chars[res++] = pre;
				if (count > 1)
				{
					string str = to_string(count);
					for (auto c : str)
						chars[res++] = c;
				}
				j = i;
			}
			if (i < N)
				pre = chars[i];
		}
		return res;
	}
};