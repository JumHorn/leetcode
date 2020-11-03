#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int findLeastNumOfUniqueInts(vector<int> &arr, int k)
	{
		map<int, int> m;
		for (auto n : arr)
			++m[n];
		vector<int> v;
		for (auto n : m)
			v.push_back(n.second);
		sort(v.begin(), v.end());
		int res = v.size();
		for (int i = 0; i < (int)v.size() && k >= v[i]; ++i)
		{
			--res;
			k -= v[i];
		}
		return res;
	}
};
