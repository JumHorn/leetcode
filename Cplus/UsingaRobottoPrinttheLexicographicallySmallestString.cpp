#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string robotWithString(string s)
	{
		string t, res;
		vector<int> count(26);
		for (auto c : s)
			++count[c - 'a'];
		int small = 0;
		for (auto c : s)
		{
			while (small < 26 && count[small] == 0)
				++small;
			while (!t.empty() && t.back() <= 'a' + small)
			{
				res.push_back(t.back());
				t.pop_back();
			}
			if (c == 'a' + small)
				res.push_back(c);
			else
				t.push_back(c);
			--count[c - 'a'];
		}
		reverse(t.begin(), t.end());
		return res + t;
	}
};