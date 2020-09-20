#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	int compareVersion(string version1, string version2)
	{
		stringstream ss1(version1), ss2(version2);
		int value1, value2, res = 0;
		char c = '.';
		while (ss1 || ss2)
		{
			if (!(ss1 >> value1))
				value1 = 0;
			ss1 >> c; //ignore .
			if (!(ss2 >> value2))
				value2 = 0;
			ss2 >> c; //ignore .
			if (value1 != value2)
				return value1 < value2 ? -1 : 1;
		}
		return 0;
	}
};