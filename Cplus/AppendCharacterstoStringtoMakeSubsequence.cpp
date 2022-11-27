#include <string>
using namespace std;

class Solution
{
public:
	int appendCharacters(string s, string t)
	{
		int N = t.size(), i = 0;
		for (auto c : s)
		{
			if (i >= N)
				break;
			if (t[i] == c)
				++i;
		}
		return N - i;
	}
};