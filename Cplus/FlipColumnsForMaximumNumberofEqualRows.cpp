#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
bit set not sufficient for it
use string instead
*/

class Solution
{
public:
	int maxEqualRowsAfterFlips(vector<vector<int>> &matrix)
	{
		unordered_map<string, int> m; //{row,count}
		int res = 0;
		for (auto &v : matrix)
		{
			if (v[0] == 1)
				arrayFlip(v);
			res = max(res, ++m[arrToString(v)]);
		}
		return res;
	}

	string arrToString(vector<int> &arr)
	{
		string res;
		for (auto n : arr)
			res.push_back(n + '0');
		return res;
	}

	void arrayFlip(vector<int> &arr)
	{
		for (auto &n : arr)
			n ^= 1;
	}
};