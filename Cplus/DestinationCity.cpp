#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string destCity(vector<vector<string>> &paths)
	{
		unordered_map<string, int> outdegree;
		for (auto &p : paths)
		{
			outdegree.insert({p[1], 0}); // if p[1] already exist do nothing
			++outdegree[p[0]];
		}
		for (auto &city : outdegree)
		{
			if (city.second == 0)
				return city.first;
		}
		return "";
	}
};