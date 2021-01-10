#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> constructDistancedSequence(int n)
	{
		vector<int> res(2 * n - 1, -1), seen(n + 1);
		backTracking(res, seen);
		return res;
	}

	bool backTracking(vector<int> &arr, vector<int> &seen)
	{
		int N = arr.size();
		int index = 0;
		while (index < N && arr[index] != -1)
			++index;
		if (index >= N)
			return true;
		int n = seen.size() - 1;
		while (seen[n] == -1)
			--n;
		for (int i = n; i >= 1; --i)
		{
			if (seen[i] == 0)
			{
				seen[i] = 1;
				if (i == 1)
				{
					arr[index] = i;
					if (backTracking(arr, seen))
						return true;
					arr[index] = -1;
				}
				else if (index + i < N && arr[index + i] == -1)
				{
					arr[index] = i;
					arr[index + i] = i;
					if (backTracking(arr, seen))
						return true;
					arr[index] = arr[index + i] = -1;
				}
				seen[i] = 0;
			}
		}
		return false;
	}
};