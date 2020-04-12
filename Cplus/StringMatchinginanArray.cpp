#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> stringMatching(vector<string>& words)
	{
		vector<string> res;
		int n = words.size();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i != j && match(words[i], words[j]))
				{
					res.push_back(words[i]);
					break;
				}
			}
		}
		return res;
	}

	bool match(const string& lhs, const string& rhs)
	{
		if (lhs.length() >= rhs.length())
			return false;
		return rhs.find(lhs) != string::npos;
	}
};
