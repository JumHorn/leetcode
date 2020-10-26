#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	int countSegments(string s)
	{
		int res = 0;
		stringstream ss(s);
		string word;
		while (ss >> word)
			++res;
		return res;
	}
};