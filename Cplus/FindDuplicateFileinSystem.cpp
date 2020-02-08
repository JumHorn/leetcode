#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> findDuplicate(vector<string>& paths)
	{
		map<string, vector<string>> m;
		for (int i = 0; i < (int)paths.size(); i++)
		{
			int j = 0, len = paths[i].size();
			while (paths[i][j] != ' ')
				++j;
			string pathname = paths[i].substr(0, j);
			int k = ++j;
			while (k < len)
			{
				j = k;
				while (paths[i][k] != '(')
					k++;
				string filename = paths[i].substr(j, k - j);
				j = ++k;
				while (paths[i][k] != ')')
					++k;
				m[paths[i].substr(j, k - j)].push_back(pathname + "/" + filename);
				k += 2;
			}
		}
		vector<vector<string>> res;
		for (auto n : m)
			if (n.second.size() > 1)
				res.push_back(n.second);
		return res;
	}
};
