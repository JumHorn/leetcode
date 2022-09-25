#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> sortPeople(vector<string> &names, vector<int> &heights)
	{
		int N = names.size();
		vector<pair<int, int>> v; //{height,index}
		for (int i = 0; i < N; ++i)
			v.push_back({heights[i], i});
		sort(v.begin(), v.end(), greater<>());
		vector<string> res;
		for (auto [_, i] : v)
			res.push_back(names[i]);
		return res;
	}
};