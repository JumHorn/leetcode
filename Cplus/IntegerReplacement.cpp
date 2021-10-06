#include <algorithm>
#include <unordered_map>
using namespace std;

/*
digits ends with
***00/10 divide
***01 decreament
***11 increament except for 3
*/

class Solution
{
public:
	int integerReplacement(int n)
	{
		int res = 0;
		for (unsigned int N = n; N > 1;)
		{
			++res;
			if ((N & 1) == 0)
				N >>= 1;
			else if (N == 3 || ((N >> 1) & 1) == 0)
				--N;
			else
				++N;
		}
		return res;
	}
};
