#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countTriplets(vector<int> &arr)
	{
		int N = arr.size(), res = 0;
		vector<int> prefix(N + 1);
		for (int i = 0; i < N; ++i)
			prefix[i + 1] = prefix[i] ^ arr[i];
		// the following O(N^2) can be optimized with map
		// for (int i = 0; i <= N; ++i)
		// {
		// 	for (int j = i + 1; j <= N; ++j)
		// 	{
		// 		if (prefix[i] == prefix[j])
		// 			res += j - i - 1;
		// 	}
		// }
		unordered_map<int, int> count, total;
		for (int i = 0; i <= N; ++i)
		{
			res += count[prefix[i]] * (i - 1) - total[prefix[i]];
			++count[prefix[i]];
			total[prefix[i]] += i;
		}
		return res;
	}
};