#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	bool hasAllCodes(string s, int k)
	{
		unsigned int num = 0, n = s.length();
		unordered_set<int> code;
		for (int i = 0; i < k; ++i)
		{
			num <<= 1;
			if (s[i] == '1')
				num |= 1;
		}
		code.insert(num);
		for (int i = k; i < n; ++i)
		{
			num <<= 1;
			if (s[i] == '1')
				num |= 1;
			code.insert(num & ((1 << k) - 1));
		}
		return code.size() >= pow(2, k);
	}
};
