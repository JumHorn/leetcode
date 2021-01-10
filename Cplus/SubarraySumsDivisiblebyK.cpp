#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int subarraysDivByK(vector<int> &A, int K)
	{
		unordered_map<int, int> m;
		int res = 0, sum = 0;
		m[0] = 1;
		for (auto &n : A)
			n = (n % K + K) % K;
		for (auto &n : A)
		{
			sum += n;
			int tmp = sum % K;
			res += m[tmp];
			m[tmp] += 1;
		}
		return res;
	}
};