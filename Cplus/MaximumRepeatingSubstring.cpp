#include <string>
using namespace std;

class Solution
{
public:
	int maxRepeating(string sequence, string word)
	{
		int res = 0;
		string s = word;
		while (sequence.find(s) != string::npos)
		{
			++res;
			s += word;
		}
		return res;
	}
};