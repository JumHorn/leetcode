#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findAllRecipes(vector<string> &recipes, vector<vector<string>> &ingredients, vector<string> &supplies)
	{
		vector<string> res;
		int N = recipes.size();
		vector<unordered_set<string>> ings;
		for (auto &v : ingredients)
		{
			ings.emplace_back();
			for (auto &s : v)
				ings.back().insert(s);
		}
		for (auto &s : supplies)
		{
			for (auto &ing : ings)
				ing.erase(s);
		}
		for (int i = 0; i < N; ++i)
		{
			if (ings[i].empty())
				res.push_back(recipes[i]);
		}

		for (int i = 0; i < (int)res.size(); ++i) //res.size() changes
		{
			for (int j = 0; j < N; ++j)
			{
				if (ings[j].empty())
					continue;
				ings[j].erase(res[i]);
				if (ings[j].empty())
					res.push_back(recipes[j]);
			}
		}

		return res;
	}
};