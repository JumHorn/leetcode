#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int mostWordsFound(vector<string> &sentences)
	{
		int res = 0;
		for (auto &s : sentences)
		{
			stringstream ss(s);
			string word;
			int count = 0;
			while (ss >> word)
				++count;
			res = max(res, count);
		}
		return res;
	}
};