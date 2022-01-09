#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestPalindrome(vector<string> &words)
	{
		unordered_map<string, int> m;
		for (auto &w : words)
			++m[w];
		unordered_set<string> seen;
		int res = 0, same = 0;
		for (auto &[w, count] : m)
		{
			if (seen.count(w) == 0)
			{
				seen.insert(w);
				string reverse_w = w;
				reverse(reverse_w.begin(), reverse_w.end());
				seen.insert(reverse_w);
				if (w == reverse_w)
				{
					if (count % 2 == 1)
					{
						same = 2;
						res += (count - 1) * 2;
					}
					else
						res += count * 2;
				}
				else
				{
					auto it = m.find(reverse_w);
					if (it != m.end())
						res += min(count, it->second) * 2 * 2;
				}
			}
		}
		return res + same;
	}
};