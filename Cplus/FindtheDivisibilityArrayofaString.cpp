#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> divisibilityArray(string word, int m)
	{
		long N = word.size(), r = 0;
		vector<int> res;
		for (auto c : word)
		{
			r = (r * 10 + c - '0') % m;
			if (r == 0)
				res.push_back(1);
			else
				res.push_back(0);
		}
		return res;
	}
};