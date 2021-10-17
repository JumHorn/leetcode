#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minMovesToSeat(vector<int> &seats, vector<int> &students)
	{
		int res = 0, N = seats.size();
		sort(seats.begin(), seats.end());
		sort(students.begin(), students.end());
		for (int i = 0; i < N; ++i)
			res += abs(seats[i] - students[i]);
		return res;
	}
};