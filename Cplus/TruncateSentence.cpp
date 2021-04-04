#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string truncateSentence(string s, int k)
	{
		stringstream ss(s);
		string res, word;
		for (int i = 0; i < k; ++i)
		{
			ss >> word;
			res += word + " ";
		}
		if (!res.empty())
			res.pop_back();
		return res;
	}
};