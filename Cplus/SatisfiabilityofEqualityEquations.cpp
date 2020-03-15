#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool equationsPossible(vector<string>& equations)
	{
		vector<vector<int>> equal(26, vector<int>(26));
		vector<vector<int>> notequal(26, vector<int>(26));
		for (int i = 0; i < 26; i++)
			equal[i][i] = 1;
		for (auto& e : equations)
		{
			if (e[1] == '=')
			{
				for (int i = 0; i < 26; i++)
				{
					if (equal[e[0] - 'a'][i] == 1)
					{
						if (notequal[i][e[3] - 'a'] == 1)
							return false;
						equal[i][e[3] - 'a'] = 1;
						equal[e[3] - 'a'][i] = 1;
					}
					if (equal[e[3] - 'a'][i] == 1)
					{
						if (notequal[i][e[0] - 'a'] == 1)
							return false;
						equal[i][e[0] - 'a'] = 1;
						equal[e[0] - 'a'][i] = 1;
					}
				}
			}
			else
			{
				for (int i = 0; i < 26; i++)
				{
					if (equal[e[0] - 'a'][i] == 1)
					{
						if (equal[i][e[3] - 'a'] == 1)
							return false;
						notequal[i][e[3] - 'a'] = 1;
						notequal[e[3] - 'a'][i] = 1;
					}
					if (equal[e[3] - 'a'][i] == 1)
					{
						if (equal[i][e[0] - 'a'] == 1)
							return false;
						notequal[i][e[0] - 'a'] = 1;
						notequal[e[0] - 'a'][i] = 1;
					}
				}
			}
		}
		return true;
	}
};
