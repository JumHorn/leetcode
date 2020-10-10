#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string customSortString(string S, string T)
	{
		vector<int> hash(26, 26);
		for (int i = 0; i < (int)S.length(); ++i)
			hash[S[i] - 'a'] = i;
		sort(T.begin(), T.end(), [&](char lhs, char rhs) { return hash[lhs - 'a'] < hash[rhs - 'a']; });
		return T;
	}
};