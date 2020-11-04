#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string makeLargestSpecial(string S)
	{
		if (S.empty())
			return S;
		vector<string> special;
		int count = 0;
		for (int i = 0, j = 0; j < (int)S.length(); ++j)
		{
			if (S[j] == '1')
				++count;
			else
				--count;

			if (count == 0)
			{
				special.push_back('1' + makeLargestSpecial(S.substr(i + 1, j - i - 1)) + '0');
				i = j + 1;
			}
		}
		sort(special.begin(), special.end(), greater<string>());
		string res;
		for (auto &s : special)
			res += s;
		return res;
	}
};