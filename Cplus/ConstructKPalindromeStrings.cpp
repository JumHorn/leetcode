#include <string>
using namespace std;

class Solution
{
public:
	bool canConstruct(string s, int k)
	{
		int count[26] = {0}, single = 0, N = s.length();
		if (k > N)
			return false;
		for (auto c : s)
			++count[c - 'a'];
		for (int i = 0; i < 26; ++i)
			single += count[i] % 2;
		return k >= single;
	}
};