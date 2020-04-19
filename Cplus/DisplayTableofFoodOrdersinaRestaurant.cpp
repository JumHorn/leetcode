#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> displayTable(vector<vector<string>>& orders)
	{
		map<int, map<string, int>> table;
		set<string> display;
		for (auto& order : orders)
		{
			++table[stoi(order[1])][order[2]];
			display.insert(order[2]);
		}
		vector<vector<string>> res;
		res.push_back({"Table"});
		for (auto& d : display)
			res[0].push_back(d);
		for (auto& t : table)
		{
			res.push_back({to_string(t.first)});
			for (auto& d : display)
				res.back().push_back(to_string(t.second[d]));
		}
		return res;
	}
};
