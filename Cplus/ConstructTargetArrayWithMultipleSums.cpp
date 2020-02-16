#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isPossible(vector<int> &target)
	{
		if (target.size() == 1)
			return target[0] == 1;
		sort(target.begin(), target.end());
		vector<int> A(target.size(), 1);
		vector<unordered_set<int>> seen(target.size());
		return backTracking(target, 0, A, target.size(), seen);
	}

	bool backTracking(vector<int> &target, int index, vector<int> &A, int sum, vector<unordered_set<int>> &seen)
	{
		int n = target.size();
		if (n == index)
			return true;
		if (seen[index].find(sum) != seen[index].end())
			return false;
		if (target[index] < sum)
		{
			seen[index].insert(sum);
			return false;
		}
		for (int i = index; i < n; i++)
		{
			for (int j = index; j < n; j++)
			{
				int tmp = A[index];
				A[index] = sum;
				if (A[index] == target[index])
				{
					if (backTracking(target, index + 1, A, sum + sum - tmp, seen))
						return true;
				}
				else
				{
					if (backTracking(target, index, A, sum + sum - tmp, seen))
						return true;
				}
				A[index] = tmp;
			}
		}
		seen[index].insert(sum);
		return false;
	}
};

int main()
{
	vector<int> v = {8, 5};
	Solution sol;
	sol.isPossible(v);
	return 0;
}