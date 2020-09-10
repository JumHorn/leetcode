#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string convert(string s, int numRows)
	{
		int N = s.length();
		if (numRows <= 1)
			return s;
		vector<string> v(numRows);
		int flag = 1;
		for (int i = 0, j = 0; i < N; ++i)
		{
			v[j].push_back(s[i]);
			j += flag;
			if (j == numRows - 1 || j == 0)
				flag = -flag;
		}
		string res;
		for (auto& str : v)
			res += str;
		return res;
	}
};
