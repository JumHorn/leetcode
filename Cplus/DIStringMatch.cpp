#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> diStringMatch(string S)
	{
		int N = S.length();
		vector<int> res(N + 1);
		int decrease = N, increase = 0;
		for (int i = 0; i < N; ++i)
		{
			if (S[i] == 'I')
				res[i] = increase++;
			else
				res[i] = decrease--;
		}
		res.back() = increase;
		return res;
	}
};