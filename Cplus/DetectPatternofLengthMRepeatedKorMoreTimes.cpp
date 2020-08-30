#include <vector>
using namespace std;

class Solution
{
public:
	bool containsPattern(vector<int>& arr, int m, int k)
	{
		for (int i = 0; i < (int)arr.size(); ++i)
		{
			int count = 1;
			for (int j = i + m; j + m <= (int)arr.size(); j += m)
			{
				if (check(arr, i, j, m))
				{
					if (++count >= k)
						return true;
				}
				else
					break;
			}
		}
		return false;
	}

	bool check(vector<int>& arr, int i, int j, int m)
	{
		for (int k = 0; k < m; ++k)
		{
			if (arr[i + k] != arr[j + k])
				return false;
		}
		return true;
	}
};
