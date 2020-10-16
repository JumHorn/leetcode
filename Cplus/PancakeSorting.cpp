#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> pancakeSort(vector<int> &arr)
	{
		int N = arr.size();
		vector<int> res;
		for (int i = 0; i < N; ++i)
		{
			int index = 0; //max index
			for (int j = 1; j < N - i; ++j)
			{
				if (arr[j] > arr[index])
					index = j;
			}
			if (index != N - i - 1)
			{
				res.push_back(index + 1);
				reverse(arr.begin(), arr.begin() + index + 1);
				res.push_back(N - i);
				reverse(arr.begin(), arr.begin() + N - i);
			}
		}
		return res;
	}
};