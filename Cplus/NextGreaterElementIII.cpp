#include <algorithm>
#include <climits>
#include <string>
using namespace std;

class Solution
{
public:
	int nextGreaterElement(int n)
	{
		string s = to_string(n);
		int N = s.length();
		int i = N;
		while (--i > 0)
		{
			if (s[i] > s[i - 1])
			{
				int j = N - 1;
				while (s[j] <= s[i - 1])
					--j;
				swap(s[i - 1], s[j]);
				reverse(s.begin() + i, s.end());
				long res = stol(s);
				return res < INT_MAX ? res : -1;
			}
		}
		return -1;
	}
};