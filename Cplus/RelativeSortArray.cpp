#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
	{
		unordered_map<int, int> m; //{arr2 value,index}
		int N = arr2.size();
		for (int i = 0; i < N; ++i)
			m[arr2[i]] = i;
		auto lambda = [&](int lhs, int rhs) {
			if (m.find(lhs) == m.end() && m.find(rhs) == m.end())
				return lhs < rhs;
			if (m.find(lhs) == m.end())
				return false;
			if (m.find(rhs) == m.end())
				return true;
			return m[lhs] < m[rhs];
		};
		sort(arr1.begin(), arr1.end(), lambda);
		return arr1;
	}
};