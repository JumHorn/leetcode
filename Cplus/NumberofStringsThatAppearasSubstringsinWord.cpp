#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numOfStrings(vector<string> &patterns, string word)
	{
		int res = 0;
		for (auto &str : patterns)
		{
			if (word.find(str) != string::npos)
				++res;
		}
		return res;
	}
};