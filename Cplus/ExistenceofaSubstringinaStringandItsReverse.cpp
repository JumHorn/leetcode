#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isSubstringPresent(string s)
	{
		vector<vector<int>> exist(26, vector<int>(26));
		int N = s.size();
		for (int i = 0; i < N - 1; ++i)
			exist[s[i] - 'a'][s[i + 1] - 'a'] = 1;
		for (int i = 0; i < N - 1; ++i)
		{
			if (exist[s[i + 1] - 'a'][s[i] - 'a'] == 1)
				return true;
		}
		return false;
	}
};