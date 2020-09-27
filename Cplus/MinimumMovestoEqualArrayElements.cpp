#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

/*
let x be the final equal array value
sum is of the original nums
x*N == moves*(N-1)+sum
and key point is that because minval must be add moves times
x=minval+moves
*/

class Solution
{
public:
	int minMoves(vector<int> &nums)
	{
		int N = nums.size();
		long min = *min_element(nums.begin(), nums.end());
		long sum = accumulate(nums.begin(), nums.end(), 0L);
		return sum - N * min;
	}
};