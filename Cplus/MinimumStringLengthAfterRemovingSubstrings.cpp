#include <string>
using namespace std;

class Solution
{
public:
	int minLength(string s)
	{
		int N = s.size(), top = -1;
		for (int i = 0; i < N; ++i)
		{
			if (top != -1)
			{
				if (s[i] == 'B' && s[top] == 'A')
					--top;
				else if (s[i] == 'D' && s[top] == 'C')
					--top;
				else
					s[++top] = s[i];
			}
			else
				s[++top] = s[i];
		}
		return top + 1;
	}
};