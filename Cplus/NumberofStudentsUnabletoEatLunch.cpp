#include <vector>
using namespace std;

class Solution
{
public:
	int countStudents(vector<int> &students, vector<int> &sandwiches)
	{
		int one = 0, zero = 0;
		for (auto n : students)
			n == 0 ? ++zero : ++one;
		for (auto n : sandwiches)
		{
			n == 0 ? --zero : --one;
			if (zero < 0 || one < 0)
				return zero + one + 1;
		}
		return 0;
	}
};