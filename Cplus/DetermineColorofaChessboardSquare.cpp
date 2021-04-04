#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	bool squareIsWhite(string coordinates)
	{
		if (isdigit(coordinates[0]))
			swap(coordinates[0], coordinates[1]);
		//{alpha,digit}
		return ((coordinates[0] - 'a') % 2 == 0 && (coordinates[1] - '1') % 2 == 1) ||
			   ((coordinates[0] - 'a') % 2 == 1 && (coordinates[1] - '1') % 2 == 0);
	}
};