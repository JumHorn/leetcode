#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int distributeCandies(vector<int> &candies)
	{
		unordered_set<int> s(candies.begin(), candies.end());
		return s.size() <= candies.size() / 2 ? s.size() : candies.size() / 2;
	}
};