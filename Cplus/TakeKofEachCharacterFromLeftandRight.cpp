#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int takeCharacters(string s, int k)
	{
		int N = s.size(), index = 0;
		vector<int> C(3); //{'a','b','c'}
		for (; index < N && (C[0] < k || C[1] < k || C[2] < k); ++index)
			++C[s[index] - 'a'];
		if (C[0] < k || C[1] < k || C[2] < k)
			return -1;
		int res = index--;
		for (int i = N - 1; i >= 0 && index >= 0; --i)
		{
			++C[s[i] - 'a'];
			while (index >= 0 && C[s[index] - 'a'] > k)
			{
				--C[s[index] - 'a'];
				--index;
			}
			res = min(res, index + 1 + N - i);
		}
		return res;
	}
};