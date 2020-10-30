#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
	{
		vector<int> res;
		int even = 0;
		for (auto n : A)
		{
			if (n % 2 == 0)
				even += n;
		}
		for (auto &query : queries)
		{
			int index = query[1];
			if (A[index] % 2 == 0)
				even -= A[index];
			A[index] += query[0];
			if (A[index] % 2 == 0)
				even += A[index];
			res.push_back(even);
		}
		return res;
	}
};