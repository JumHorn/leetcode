#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canBeEqual(vector<int> &target, vector<int> &arr)
	{
		unordered_map<int, int> m;
		for (auto n : target)
			++m[n];
		for (auto n : arr)
		{
			if (--m[n] == 0)
				m.erase(n);
		}
		return m.empty();
	}
};