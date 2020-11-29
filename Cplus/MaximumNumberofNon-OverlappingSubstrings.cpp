#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> maxNumOfSubstrings(string s)
	{
		vector<int> left(26), right(26);
		int N = s.length();
		for (int i = 0; i < N; ++i)
			right[s[i] - 'a'] = i;
		for (int i = N - 1; i >= 0; --i)
			left[s[i] - 'a'] = i;

		vector<string> res(1);
		int last_right = N;
		for (int i = 0; i < N; ++i)
		{
			if (i == left[s[i] - 'a'])
			{
				int rightmost = checkStr(s, i, left, right);
				if (rightmost != -1)
				{
					if (i > last_right)
						res.push_back("");
					last_right = rightmost;
					res.back() = s.substr(i, rightmost - i + 1);
				}
			}
		}
		return res;
	}

	int checkStr(const string &s, int start, vector<int> &left, vector<int> &right)
	{
		int maxright = right[s[start] - 'a'];
		for (int i = start; i < maxright; ++i)
		{
			if (left[s[i] - 'a'] < start)
				return -1;
			maxright = max(maxright, right[s[i] - 'a']);
		}
		return maxright;
	}
};