#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool areOccurrencesEqual(string s)
	{
		vector<int> count(26);
		for (auto c : s)
			++count[c - 'a'];
		int freq = 0;
		for (auto n : count)
		{
			if (n != 0)
			{
				if (freq == 0)
					freq = n;
				if (freq != n)
					return false;
			}
		}
		return true;
	}
};