#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string removeDuplicateLetters(string s)
	{
		vector<int> count(26), seen(26);
		for (auto c : s)
			++count[c - 'a'];
		string res;
		for (auto c : s)
		{
			if (seen[c - 'a'] == 0)
			{
				while (!res.empty() && count[res.back() - 'a'] != 0 && res.back() > c)
				{
					seen[res.back() - 'a'] = 0;
					res.pop_back();
				}
				res.push_back(c);
				seen[c - 'a'] = 1;
			}
			--count[c - 'a'];
		}
		return res;
	}
};