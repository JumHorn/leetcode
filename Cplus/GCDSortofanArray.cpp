#include <unordered_map>
#include <vector>
using namespace std;

//DSU minimum version
class DSU
{
public:
	DSU(int size) : parent(size)
	{
		for (int i = 0; i < size; ++i)
			parent[i] = i;
	}

	int Find(int x)
	{
		if (x != parent[x])
			parent[x] = Find(parent[x]);
		return parent[x];
	}

	bool Union(int x, int y)
	{
		int xp = Find(x), yp = Find(y);
		if (xp == yp)
			return false;
		parent[yp] = xp;
		return true;
	}

private:
	vector<int> parent;
};
/********end of DSU minimum version********/

class Solution
{
public:
	bool gcdSort(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<int>> data(N);
		DSU dsu(N);
		vector<int> factor(1e5 + 1, -1); //{primer,index}
		for (int i = 0; i < N; ++i)
		{
			for (int j = 2; j * j <= nums[i]; ++j)
			{
				if (nums[i] % j == 0)
				{
					if (factor[j] == -1)
						factor[j] = i;
					else
						dsu.Union(i, factor[j]);
					if (factor[nums[i] / j] == -1)
						factor[nums[i] / j] = i;
					else
						dsu.Union(i, factor[nums[i] / j]);
				}
			}
			if (factor[nums[i]] == -1)
				factor[nums[i]] = i;
			else
				dsu.Union(i, factor[nums[i]]);
		}
		for (int i = 0; i < N; ++i)
			data[dsu.Find(i)].push_back(nums[i]);
		for (auto &v : data)
			sort(v.begin(), v.end(), greater<int>());
		auto &tmp = data[dsu.Find(0)];
		int pre = tmp.back();
		tmp.pop_back();
		for (int i = 1; i < N; ++i)
		{
			auto &v = data[dsu.Find(i)];
			int val = v.back();
			v.pop_back();
			if (val < pre)
				return false;
			pre = val;
		}
		return true;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}
};