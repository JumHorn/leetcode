#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int primePalindrome(int N)
	{
		string s = to_string(N);
		int len = s.length();
		string half = s.substr(0, len / 2 + len % 2);
		int flag = 0;
		if (len % 2 != 0)
			flag = 1;
		int num = stoi(half);
		len = half.length();
		while (true)
		{
			string half = to_string(num);
			if (len != (int)half.length())
			{
				flag = 1 - flag;
				len = half.length();
				if (flag == 0)
				{
					len--;
					half = half.substr(0, len);
				}
			}
			string last = half.substr(0, half.length() - flag);
			reverse(last.begin(), last.end());
			int res = stoi(half + last);
			if (res >= N && isPrimer(res))
				return res;
			num++;
		}
		return 0;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (int i = 2; i * i <= N; i++)
			if (N % i == 0)
				return false;
		return true;
	}
};