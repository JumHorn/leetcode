#include <algorithm>
#include <string>
#include <unordered_set>
using namespace std;

/*
Permutation of Combinations
n! / (m[1]! * m[2]! * .. * m[i]!)
*/

class Solution
{
public:
	int numTilePossibilities(string tiles)
	{
		sort(tiles.begin(), tiles.end());
		string instance;
		unordered_set<string> combination;
		return dfs(tiles, 0, instance, combination) - 1;
	}

	int dfs(string &tiles, int index, string &instance, unordered_set<string> &combination)
	{
		if (index >= (int)tiles.size())
			return combination.insert(instance).second ? permutation(instance) : 0;
		int res = 0;
		res += dfs(tiles, index + 1, instance, combination);
		instance.push_back(tiles[index]);
		res += dfs(tiles, index + 1, instance, combination);
		instance.pop_back();
		return res;
	}

	int permutation(const string &s)
	{
		int fact[8] = {1, 1, 2, 6, 24, 120, 720, 5040}; //{0!,1!,2!,3!,...}
		int count[26] = {0};
		for (auto c : s)
			++count[c - 'A'];
		int res = fact[s.size()];
		for (auto n : count)
			res /= fact[n];
		return res;
	}
};