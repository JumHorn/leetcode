#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> shortestToChar(string S, char C)
	{
		int N = S.length();
		vector<int> res;
		int pre = -1, cur = -1;
		for (int i = 0, j = 0; i < N; ++i)
		{
			if (i > cur)
			{
				pre = cur;
				while (j < N && S[j] != C)
					++j;
				cur = j++;
			}
			int d = N;
			if (pre >= 0)
				d = min(d, i - pre);
			if (cur < N)
				d = min(d, cur - i);
			res.push_back(d);
		}
		return res;
	}
};