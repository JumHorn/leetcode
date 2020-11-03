#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string kthSmallestPath(vector<int> &destination, int k)
	{
		int H = destination[1], V = destination[0], N = H + V;
		string res(H + V, 'V');
		for (int i = 0; i < N && H > 0; ++i)
		{
			int count = combination(H + V - 1, V);
			if (k > count)
			{
				--V;
				k -= count;
			}
			else
			{
				--H;
				res[i] = 'H';
			}
		}
		return res;
	}

	int combination(int n, int m)
	{
		int res = 1;
		for (int i = 1; i <= m; ++i)
			res = res * (n - m + i) / i;
		return res;
	}
};