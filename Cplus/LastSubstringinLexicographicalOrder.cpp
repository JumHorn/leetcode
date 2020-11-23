#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string lastSubstring(string s)
	{
		int N = s.length(), i = 0;
		for (int j = 1, k = 0; j + k < N;)
		{
			if (s[i + k] == s[j + k])
				++k;
			else if (s[i + k] < s[j + k])
			{
				i = j++;
				k = 0;
			}
			else
			{
				j += k + 1;
				k = 0;
			}
		}
		return s.substr(i);
	}
};