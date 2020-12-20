#include <string>
using namespace std;

class Solution
{
public:
	string reformatNumber(string number)
	{
		string num;
		for (auto c : number)
		{
			if (isdigit(c))
				num.push_back(c);
		}
		int N = num.length();
		int n = N / 3 - (N % 3 == 1 ? 1 : 0);
		string res;
		for (int i = 0; i < n; ++i)
			res += "-" + num.substr(i * 3, 3);
		if (N % 3 == 1)
		{
			res += "-" + num.substr(n * 3, 2);
			res += "-" + num.substr(n * 3 + 2, 2);
		}
		else if (N % 3 == 2)
		{
			res += "-" + num.substr(N / 3 * 3, 2);
		}
		return res.substr(1);
	}
};