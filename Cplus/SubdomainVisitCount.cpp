#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> subdomainVisits(vector<string> &cpdomains)
	{
		unordered_map<string, int> m; //{domain,count}
		for (auto &cp : cpdomains)
		{
			stringstream ss(cp);
			int count;
			string domain;
			ss >> count >> domain;
			m[domain] += count;
			for (int i = 0; i < (int)domain.length(); ++i)
			{
				if (domain[i] == '.')
					m[domain.substr(i + 1)] += count;
			}
		}
		vector<string> res;
		for (auto &n : m)
			res.push_back(to_string(n.second) + " " + n.first);
		return res;
	}
};