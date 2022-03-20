#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	//Fast Walsh Hadamard Transform
	// Please remind that these codes are valid only when degree(P) = N = 2^k
	void fwht_and(vector<int> &v, bool inverse)
	{
		int N = v.size();
		for (int m = 1; 2 * m <= N; m *= 2)
		{
			for (int i = 0; i < N; i += 2 * m)
			{
				for (int j = 0; j < m; ++j)
				{
					auto x = v[i + j];
					auto y = v[i + j + m];
					if (!inverse)
					{
						v[i + j] = y;
						v[i + j + m] = x + y;
					}
					else
					{
						v[i + j] = -x + y;
						v[i + j + m] = x;
					}
				}
			}
		}
	}
	/********end of Fast Walsh Hadamard Transform********/

	int countTriplets(vector<int> &A)
	{
		vector<int> v(1 << 16);
		for (auto n : A)
			++v[n];
		fwht_and(v, false);
		for (auto &n : v)
			n = n * n * n;
		fwht_and(v, true);
		return v[0];
	}
};