#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> splitWordsBySeparator(vector<string> &words, char separator)
	{
		vector<string> res;
		for (auto &w : words)
		{
			stringstream ss(w);
			string token;
			while (getline(ss, token, separator))
			{
				if (!token.empty())
					res.push_back(token);
			}
		}
		return res;
	}
};