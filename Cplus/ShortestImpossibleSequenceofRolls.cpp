#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int shortestSequence(vector<int> &rolls, int k)
	{
		int res = 0;
		unordered_set<int> s;
		for (auto n : rolls)
		{
			s.insert(n);
			if (s.size() == k)
			{
				s.clear();
				++res;
			}
		}
		return res + 1;
	}
};