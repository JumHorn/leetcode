#include <map>
#include <vector>
using namespace std;

class Solution
{
public:
	int partitionDisjoint(vector<int> &A)
	{
		map<int, int> count; //{val,count}
		for (auto n : A)
			++count[n];
		int N = A.size();
		int res = 1, maxval = A[0];
		if (--count[A[0]] == 0)
			count.erase(A[0]);
		for (int i = 1; i < N && maxval > count.begin()->first; ++i)
		{
			res = i + 1;
			maxval = max(maxval, A[i]);
			if (--count[A[i]] == 0)
				count.erase(A[i]);
		}
		return res;
	}
};