#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canBeEqual(vector<int>& target, vector<int>& arr)
	{
		unordered_map<int, int> m;
		for (auto n : target)
			++m[n];
		for (auto n : arr)
			--m[n];
		for (auto n : m)
		{
			if (n.second != 0)
				return false;
		}
		return true;
	}
};
