#include <string>
using namespace std;

class Solution
{
public:
	string longestNiceSubstring(string s)
	{
		int N = s.length();
		for (int i = N; i > 0; --i)
		{
			for (int j = 0; j <= N - i; ++j)
			{
				int hash[256] = {0};
				for (int k = j; k < j + i; ++k)
					hash[s[k]] = 1;
				char c = 'A';
				for (; c <= 'Z'; ++c)
				{
					if (hash[c] != hash[c + 'a' - 'A'])
						break;
				}
				if (c > 'Z')
				{
					for (c = 'a'; c <= 'z'; ++c)
					{
						if (hash[c] != hash[c - 'a' + 'A'])
							break;
					}
					if (c > 'z')
						return s.substr(j, i);
				}
			}
		}
		return "";
	}
};