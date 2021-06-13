#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool makeEqual(vector<string> &words)
	{
		vector<int> count(26);
		for (auto &w : words)
		{
			for (auto c : w)
				++count[c - 'a'];
		}
		int N = words.size();
		for (auto n : count)
		{
			if (n % N != 0)
				return false;
		}
		return true;
	}
};