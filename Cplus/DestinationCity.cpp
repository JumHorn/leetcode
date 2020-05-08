#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	string destCity(vector<vector<string>>& paths)
	{
		unordered_set<string> start, end;
		for (auto& p : paths)
		{
			start.insert(p[0]);
			end.insert(p[1]);
		}
		for (auto& city : end)
		{
			if (start.find(city) == start.end())
				return city;
		}
		return "";
	}
};
