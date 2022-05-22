#include <string>
using namespace std;

class Solution
{
public:
	int percentageLetter(string s, char letter)
	{
		int count = 0, N = s.length();
		for (auto c : s)
		{
			if (c == letter)
				++count;
		}
		return (int)count * 1.0 / N * 100;
	}
};