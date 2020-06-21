#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> getFolderNames(vector<string>& names)
	{
		unordered_map<string, int> m;
		vector<string> res;
		for (auto& name : names)
		{
			if (m.find(name) == m.end())
				res.push_back(name);
			else
			{
				int n = m[name];
				while (m.find(name + "(" + to_string(n) + ")") != m.end())
					++n;
				res.push_back(name + "(" + to_string(n) + ")");
				++m[name + "(" + to_string(n) + ")"];
				m[name] = n;
			}
			++m[name];
		}
		return res;
	}
};
