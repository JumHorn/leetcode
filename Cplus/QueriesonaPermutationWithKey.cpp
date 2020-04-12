#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> processQueries(vector<int>& queries, int m)
	{
		vector<int> permutation(m), res;
		for (int i = 0; i < m; i++)
			permutation[i] = i + 1;
		for (auto n : queries)
		{
			for (int i = 0; i < m; i++)
			{
				if (n == permutation[i])
				{
					res.push_back(i);
					int tmp = n;
					while (--i >= 0)
						permutation[i + 1] = permutation[i];
					permutation[0] = tmp;
					break;
				}
			}
		}
		return res;
	}
};
