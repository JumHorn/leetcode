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
		while (ss1 && ss2)
		{
			ss1 >> value1;
			ss1 >> c; //ignore .
			ss2 >> value2;
			ss2 >> c; //ignore .
			if (value1 != value2)
				return value1 < value2 ? -1 : 1;
		}
		while (ss1)
		{
			ss1 >> value1;
			ss1 >> c; //ignore .
			if (value1 != 0)
				return 1;
		}
		while (ss2)
		{
			ss2 >> value2;
			ss2 >> c; //ignore .
			if (value2 != 0)
				return -1;
		}
		return 0;
	}
};