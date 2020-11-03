#include <string>
using namespace std;

class Solution
{
public:
	string getHappyString(int n, int k)
	{
		int rank = 1 << (n - 1);
		if (3 * rank < k)
			return "";
		string res(n, 'a');
		res[0] = (k - 1) / rank + 'a';
		for (int i = 1; i < n; ++i)
		{
			k = (k - 1) % rank + 1;
			rank >>= 1;
			res[i] = (k - 1) / rank == 0 ? 'a' + (res[i - 1] == 'a' ? 1 : 0)
										 : 'b' + (res[i - 1] != 'c' ? 1 : 0);
		}
		return res;
	}
};