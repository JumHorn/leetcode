#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> decrypt(vector<int> &code, int k)
	{
		int N = code.size();
		vector<int> res;
		for (int i = 1; i < N; ++i)
			code[i] += code[i - 1];
		for (int i = 0; i < N; ++i)
		{
			int n = 0;
			if (k >= 0)
			{
				if (i + k < N)
					n = code[i + k] - code[i];
				else
				{
					n = code[N - 1] - code[i];
					n += code[i + k - N];
				}
			}
			else
			{
				if (i + k > 0)
					n = code[i - 1] - code[i + k - 1];
				else
				{
					n = i > 0 ? code[i - 1] : 0;
					n += code[N - 1] - code[i + k + N - 1];
				}
			}
			res.push_back(n);
		}
		return res;
	}
};