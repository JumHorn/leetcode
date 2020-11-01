#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
	{
		unordered_map<int, int> m; //{value of first pieces,index}
		for (int i = 0; i < (int)pieces.size(); ++i)
			m[pieces[i][0]] = i;
		for (int i = 0; i < (int)arr.size();)
		{
			if (m.find(arr[i]) == m.end())
				return false;
			int index = m[arr[i]];
			++i;
			for (int j = 1; j < (int)pieces[index].size(); ++j)
			{
				if (pieces[index][j] != arr[i])
					return false;
				++i;
			}
		}
		return true;
	}
};