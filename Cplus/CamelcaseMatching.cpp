#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<bool> camelMatch(vector<string>& queries, string pattern)
	{
		vector<bool> res(queries.size());
		for (int i = 0; i < (int)queries.size(); i++)
			res[i] = isMath(queries[i], pattern);
		return res;
	}

	bool isMath(string& query, string& pattern)
	{
		int n = pattern.size(), m = query.size(), i = 0, j = 0;
		while (i < n && j < m)
		{
			if (query[j] == pattern[i])
				i++;
			else
			{
				if (query[j] < 'a' || query[j] > 'z')
					return false;
			}
			j++;
		}
		while (j < m)
		{
			if (query[j] < 'a' || query[j] > 'z')
				return false;
			j++;
		}
		return i == n;
	}
};
