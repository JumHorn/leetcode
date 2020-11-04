#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int countTriplets(vector<int> &A)
	{
		int N = A.size();
		unordered_map<int, int> m;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				++m[A[i] & A[j]];
		}
		int res = 0;
		for (int i = 0; i < N; ++i)
		{
			for (auto n : m)
			{
				if ((A[i] & n.first) == 0)
					res += n.second;
			}
		}
		return res;
	}
};