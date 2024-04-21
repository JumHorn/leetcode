#include <string>
using namespace std;

class Solution
{
public:
	int numberOfSpecialChars(string word)
	{
		int res = 0;
		for (char c = 'a'; c <= 'z'; ++c)
		{
			int meet = 0;
			char d = 'A' + c - 'a';
			for (auto n : word)
			{
				if (n == d)
				{
					if (meet == 0)
						break;
					meet = 2;
				}
				if (n == c)
				{
					if (meet == 2)
					{
						meet = 0;
						break;
					}
					if (meet == 0)
						meet = 1;
				}
			}
			if (meet == 2)
				++res;
		}
		return res;
	}
};