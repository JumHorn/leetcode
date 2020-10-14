#include <algorithm>
#include <vector>
using namespace std;

/*
A summary of the properties of a Beautiful Array:

I. Given a beautiful array A, the following properties holds:
(1) A' = A*c is a Beautiful array
(2) A' = A + c is a Beautiful array
(3) if A' is an array obtained by deleting some element in A, then A' is still Beautiful.

II. Given two Beautiful array A and B, whose elements are odd and even respectively,
then concatenation array A + B is still Beautiful.
*/

class Solution
{
public:
	vector<int> beautifulArray(int N)
	{
		vector<int> res = {1};
		while ((int)res.size() < N)
		{
			vector<int> next;
			for (auto n : res)
			{
				if (n * 2 - 1 <= N)
					next.push_back(n * 2 - 1);
			}
			for (auto n : res)
			{
				if (n * 2 <= N)
					next.push_back(n * 2);
			}
			res = next;
		}
		return res;
	}
};