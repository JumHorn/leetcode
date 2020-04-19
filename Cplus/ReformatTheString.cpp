#include <string>
using namespace std;

class Solution
{
public:
	string reformat(string s)
	{
		string number, alpha;
		for (auto c : s)
		{
			if (c >= '0' && c <= '9')
				number.push_back(c);
			else
				alpha.push_back(c);
		}
		int n1 = number.length(), n2 = alpha.length();
		if (abs(n1 - n2) > 1)
			return "";
		if (n1 >= n2)
			return merge(number, alpha);
		return merge(alpha, number);
	}

	string merge(string& a, string& b)
	{
		string res;
		for (int i = 0; i < (int)b.length(); i++)
		{
			res.push_back(a[i]);
			res.push_back(b[i]);
		}
		if (a.length() > b.length())
			res.push_back(a.back());
		return res;
	}
};
