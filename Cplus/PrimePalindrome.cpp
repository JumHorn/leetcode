#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int primePalindrome(int N)
	{
		string s = to_string(N);
		int len = (s.length() + 1) / 2, odd = s.length() % 2;
		for (int num = stoi(s.substr(0, len));; ++num)
		{
			string half = to_string(num);
			int halflen = half.length();
			if (len != halflen)
			{
				len = halflen - odd;
				half = half.substr(0, len);
				odd = 1 - odd;
			}
			string last = half.substr(0, halflen - odd);
			reverse(last.begin(), last.end());
			int res = stoi(half + last);
			if (res >= N && isPrimer(res))
				return res;
		}
		return 0;
	}

	bool isPrimer(int N)
	{
		if (N == 1)
			return false;
		for (int i = 2; i * i <= N; ++i)
		{
			if (N % i == 0)
				return false;
		}
		return true;
	}
};