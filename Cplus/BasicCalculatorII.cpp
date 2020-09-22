#include <string>
using namespace std;

class Solution
{
public:
	int calculate(string s)
	{
		int N = s.length();
		int res = 0, pre = 0, i = 0;
		while (i < N && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
			++i;
		if (i == N)
			return stoi(s);
		res = pre = stoi(s.substr(0, i));
		while (i < N)
		{
			int j = i + 1;
			while (j < N && s[j] != '+' && s[j] != '-' && s[j] != '*' && s[j] != '/')
				++j;
			if (s[i] == '+')
				pre = stoi(s.substr(i + 1, j - i - 1));
			else if (s[i] == '-')
				pre = -stoi(s.substr(i + 1, j - i - 1));
			else if (s[i] == '*')
			{
				res -= pre;
				pre *= stoi(s.substr(i + 1, j - i - 1));
			}
			else // '/'
			{
				res -= pre;
				pre /= stoi(s.substr(i + 1, j - i - 1));
			}
			res += pre;
			i = j;
		}
		return res;
	}
};