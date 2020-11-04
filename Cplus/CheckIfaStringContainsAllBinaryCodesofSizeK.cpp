#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool hasAllCodes(string s, int k)
	{
		unsigned int num = 0, N = s.length();
		if (k >= N)
			return false;
		unordered_set<int> code;
		for (int i = 0; i < k; ++i)
		{
			num <<= 1;
			if (s[i] == '1')
				num |= 1;
		}
		code.insert(num);
		for (int i = k; i < N; ++i)
		{
			num <<= 1;
			if (s[i] == '1')
				num |= 1;
			code.insert(num & ((1 << k) - 1));
		}
		return code.size() >= (1 << k);
	}
};