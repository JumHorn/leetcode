#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> alertNames(vector<string> &keyName, vector<string> &keyTime)
	{
		map<string, vector<string>> m; //{name,{last time,count}}
		vector<string> res;
		for (int i = 0; i < (int)keyName.size(); ++i)
			m[keyName[i]].push_back(keyTime[i]);
		for (auto &n : m)
		{
			auto &v = n.second;
			sort(v.begin(), v.end());
			for (int i = 2, j = 0; i < v.size(); ++i)
			{
				if (timeDiff(v[j], v[i]))
				{
					res.push_back(n.first);
					break;
				}
				++j;
			}
		}
		return res;
	}

	bool timeDiff(const string &t1, const string &t2)
	{
		int hour1 = stoi(t1.substr(0, 2)), minute1 = stoi(t1.substr(3));
		int hour2 = stoi(t2.substr(0, 2)), minute2 = stoi(t2.substr(3));
		if (hour1 == hour2)
			return true;
		int diff = (hour2 - hour1) * 60 + minute2 - minute1;
		return diff >= 0 && diff <= 60;
	}
};