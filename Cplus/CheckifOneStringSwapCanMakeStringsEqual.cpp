#include <string>
using namespace std;

class Solution
{
public:
	bool areAlmostEqual(string s1, string s2)
	{
		int N = s1.length();
		string w1, w2;
		for (int i = 0; i < N; ++i)
		{
			if (s1[i] != s2[i])
			{
				w1.push_back(s1[i]);
				w2.push_back(s2[i]);
				if (w1.length() > 2)
					return false;
			}
		}
		if (w1.empty())
			return true;
		if (w1.length() == 1)
			return false;
		return w1[0] == w2[1] && w1[1] == w2[0];
	}
};