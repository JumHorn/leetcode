#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> ambiguousCoordinates(string S)
	{
		vector<string> res;
		int n = S.length();
		for (int i = 1; i < n - 2; i++)
		{
			vector<string> x = possibleNumber(S.substr(1, i));
			vector<string> y = possibleNumber(S.substr(i + 1, n - 2 - i));
			for (auto n : x)
				for (auto m : y)
					res.push_back("(" + n + ", " + m + ")");
		}
		return res;
	}

	vector<string> possibleNumber(string s)
	{
		if (s.length() <= 1)
			return {s};
		if (s[0] == '0')
		{
			int i = 1;
			while (i < (int)s.length() && s[i] == '0')
				i++;
			if (i == (int)s.length() || s.back() == '0')
				return {};
			return {"0." + s.substr(1)};
		}
		if (s.back() == '0')
			return {s};
		vector<string> res;
		res.push_back(s);
		for (int i = 0; i < (int)s.length() - 1; i++)
			res.push_back(s.substr(0, i + 1) + "." + s.substr(i + 1));
		return res;
	}
};