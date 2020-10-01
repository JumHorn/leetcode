#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> findDuplicate(vector<string> &paths)
	{
		unordered_map<string, vector<string>> m;
		for (auto path : paths)
		{
			stringstream ss(path);
			string dir, file;
			getline(ss, dir, ' ');
			while (getline(ss, file, ' '))
			{
				int index = file.find('(');
				string fileName = dir + '/' + file.substr(0, index);
				string fileContent = file.substr(index + 1, file.size() - 1 - index - 1);
				m[fileContent].push_back(fileName);
			}
		}
		vector<vector<string>> res;
		for (auto &n : m)
		{
			if (n.second.size() > 1)
				res.push_back(n.second);
		}
		return res;
	}
};