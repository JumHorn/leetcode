#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool pyramidTransition(string bottom, vector<string> &allowed)
	{
		vector<vector<vector<int>>> triangle(7, vector<vector<int>>(7, vector<int>(7)));
		for (auto &str : allowed)
			triangle[str[0] - 'A'][str[1] - 'A'][str[2] - 'A'] = 1;
		string nextbottom;
		unordered_set<string> seen;
		return backTracking(bottom, 0, nextbottom, seen, triangle);
	}

	bool backTracking(string &bottom, int index, string &nextbottom, unordered_set<string> &seen, vector<vector<vector<int>>> &triangle)
	{
		int N = bottom.size();
		if (N == 1)
			return true;
		if (seen.find(bottom) != seen.end())
			return false;
		if (nextbottom.size() == N - 1)
		{
			string next, newbottom(nextbottom);
			return backTracking(newbottom, 0, next, seen, triangle);
		}
		for (int i = 0; i < 7; ++i)
		{
			if (triangle[bottom[index] - 'A'][bottom[index + 1] - 'A'][i] == 1)
			{
				nextbottom.push_back('A' + i);
				if (backTracking(bottom, index + 1, nextbottom, seen, triangle))
					return true;
				nextbottom.pop_back();
			}
		}
		if (index == 0)
			seen.insert(bottom);
		return false;
	}
};