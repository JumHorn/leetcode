#include <algorithm>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
	string smallestSubsequence(string text)
	{
		vector<int> v(26);
		vector<char> tmp;
		for (auto n : text)
			v[n - 'a']++;
		int i = -1;
		while (++i < 26)
			if (v[i] != 0)
				break;
		string res;
		for (auto n : text)
		{
			if (n - 'a' == i)
			{
				res += n;
				v[i] = 0;
				tmp.clear();
			}
			else if (n - 'a' > i && v[n - 'a'] != 0)
			{
				auto iter = find(tmp.begin(), tmp.end(), n);
				if (iter == tmp.end())
				{
					while (!tmp.empty() && n < tmp.back())
						tmp.pop_back();
					tmp.push_back(n);
				}
				if (--v[n - 'a'] == 0)
				{
					auto iter = tmp.begin();
					while (iter != tmp.end())
					{
						res += *iter;
						v[*iter - 'a'] = 0;
						if (*iter == n)
							break;
						++iter;
					}
					tmp.erase(tmp.begin(), ++iter);
				}
			}

			while (i < 26)
			{
				if (v[i] != 0)
					break;
				i++;
			}
			if (i >= 26)
				break;
		}
		return res;
	}
};