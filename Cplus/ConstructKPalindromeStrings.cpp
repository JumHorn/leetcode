#include <string>
using namespace std;

class Solution
{
public:
	bool canConstruct(string s, int k)
	{
		int count[26] = {0}, single = 0, n = s.length();
		if (k > n)
			return false;
		for (auto c : s)
			++count[c - 'a'];
		for (int i = 0; i < 26; i++)
		{
			if (count[i] % 2 == 1)
			{
				++single;
				--count[i];
			}
		}
		return k >= single;
	}
};
