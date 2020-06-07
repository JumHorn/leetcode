#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getStrongest(vector<int>& arr, int k)
	{
		int n = arr.size();
		sort(arr.begin(), arr.end());
		int mid = arr[(n - 1) / 2];
		auto f = [=](int a, int b) {
			if (abs(a - mid) != abs(b - mid))
				return abs(a - mid) < abs(b - mid);
			return a < b;
		};
		make_heap(arr.begin(), arr.end(), f);
		vector<int> res;
		for (int i = 0; i < k; i++)
		{
			pop_heap(arr.begin(), arr.begin() + n, f);
			res.push_back(arr[--n]);
		}
		return res;
	}
};
