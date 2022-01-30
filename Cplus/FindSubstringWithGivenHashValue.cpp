#include <string>
using namespace std;

class Solution
{
public:
	string subStrHash(string s, int power, int modulo, int k, int hashValue)
	{
		long hash = 0, p = 1, N = s.length();
		for (int i = N - 1; i >= N - k; --i)
			hash = (hash * power + (s[i] - 'a' + 1)) % modulo;
		for (int i = 0; i < k - 1; ++i)
			p = p * power % modulo;
		int index = 0;
		if (hash == hashValue)
			index = N - k;
		for (int i = N - k - 1; i >= 0; --i)
		{
			hash = (hash - (s[i + k] - 'a' + 1) * p % modulo + modulo) % modulo;
			hash = (hash * power + (s[i] - 'a' + 1)) % modulo;
			if (hash == hashValue)
				index = i;
		}
		return s.substr(index, k);
	}
};