#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<long long> getDistances(vector<int> &arr)
	{
		unordered_map<long long, long long> m, count;
		int N = arr.size();
		vector<long long> res(N);
		for (int i = 0; i < N; ++i)
		{
			res[i] += (count[arr[i]]++) * i - m[arr[i]];
			m[arr[i]] += i;
		}

		m.clear();
		count.clear();
		for (int i = N - 1; i >= 0; --i)
		{
			res[i] += (count[arr[i]]++) * (N - 1 - i) - m[arr[i]];
			m[arr[i]] += (N - 1 - i);
		}
		return res;
	}
};