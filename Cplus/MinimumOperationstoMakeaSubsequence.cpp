#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &target, vector<int> &arr)
	{
		unordered_map<int, int> m; //{val,index}
		for (int i = 0; i < (int)target.size(); ++i)
			m[target[i]] = i;
		vector<int> index;
		for (auto n : arr)
		{
			if (m.find(n) != m.end())
				index.push_back(m[n]);
		}
		int N = index.size();
		vector<int> LIS;
		for (int i = 0; i < N; ++i)
		{
			int lo = 0, hi = LIS.size();
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (LIS[mi] < index[i])
					lo = mi + 1;
				else
					hi = mi;
			}
			if (lo == LIS.size())
				LIS.push_back(index[i]);
			else
				LIS[lo] = index[i];
		}
		return target.size() - LIS.size();
	}
};