#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool uniqueOccurrences(vector<int> &arr)
	{
		unordered_map<int, int> m;
		for (auto n : arr)
			++m[n];
		unordered_set<int> s;
		for (auto &n : m)
			s.insert(n.second);
		return m.size() == s.size();
	}
};