#include <string>
using namespace std;

class Solution
{
public:
	int numJewelsInStones(string J, string S)
	{
		int hash['z' - 'A' + 1] = {0};
		for (auto c : S)
			++hash[c - 'A'];
		int res = 0;
		for (auto c : J)
			res += hash[c - 'A'];
		return res;
	}
};