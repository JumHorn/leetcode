#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	long long appealSum(string s)
	{
		long long res = 0;
		int N = s.length();
		vector<int> suffix(N);
		vector<int> v(26, N);
		for (int i = N - 1; i >= 0; --i)
		{
			int index = s[i] - 'a';
			suffix[i] = v[index] - i;
			v[index] = i;
		}

		for (int i = 0; i < N; ++i)
			res += (i + 1) * suffix[i];
		return res;
	}
};