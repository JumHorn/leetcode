#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumTime(string s)
	{
		int N = s.length();
		vector<int> left(N), right(N);
		//left
		if (s[0] == '1')
			left[0] = 1;
		for (int i = 1; i < N; ++i)
		{
			left[i] = left[i - 1];
			if (s[i] == '1')
				left[i] = min(i + 1, left[i - 1] + 2);
		}
		//right
		if (s[N - 1] == '1')
			right[N - 1] = 1;
		for (int i = N - 2; i >= 0; --i)
		{
			right[i] = right[i + 1];
			if (s[i] == '1')
				right[i] = min(N - i, right[i + 1] + 2);
		}
		int res = min(right[0], left[N - 1]);
		for (int i = 0; i < N - 1; ++i)
			res = min(res, left[i] + right[i + 1]);
		return res;
	}
};