#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getStrongest(vector<int> &arr, int k)
	{
		int N = arr.size();
		sort(arr.begin(), arr.end());
		int mid = arr[(N - 1) / 2];
		auto f = [&](int a, int b) {
			if (abs(a - mid) != abs(b - mid))
				return abs(a - mid) < abs(b - mid);
			return a < b;
		};
		make_heap(arr.begin(), arr.end(), f);
		vector<int> res;
		for (int i = 0; i < k; ++i)
		{
			pop_heap(arr.begin(), arr.begin() + N, f);
			res.push_back(arr[--N]);
		}
		return res;
	}
};