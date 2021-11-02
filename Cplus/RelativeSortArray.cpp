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
		auto lambda = [&](int lhs, int rhs)
		{
			auto it1 = m.find(lhs), it2 = m.find(rhs);
			if (it1 == m.end() && it2 == m.end())
				return lhs < rhs;
			if (it1 == m.end())
				return false;
			if (it2 == m.end())
				return true;
			return it1->second < it2->second;
		};
		sort(arr1.begin(), arr1.end(), lambda);
		return arr1;
	}
};