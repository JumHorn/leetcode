#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool hasAllCodes(string s, int k)
	{
		int N = s.length();
		if ((1 << k) > N - k + 1)
			return false;
		unordered_set<int> code;
		unsigned int num = 0;
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
			code.insert(num & ((1u << k) - 1));
		}
		return code.size() >= (1u << k);
	}
};