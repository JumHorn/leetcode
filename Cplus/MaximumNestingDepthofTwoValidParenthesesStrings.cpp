#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxDepthAfterSplit(string seq)
	{
		vector<int> res;
		int count = 0;
		for (auto c : seq)
		{
			if (c == '(')
			{
				++count;
				res.push_back(count & 1);
			}
			else
			{
				--count;
				res.push_back(1 ^ count & 1);
			}
		}
		return res;
	}
};