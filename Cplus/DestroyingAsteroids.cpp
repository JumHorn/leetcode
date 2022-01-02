#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	bool asteroidsDestroyed(int mass, vector<int> &asteroids)
	{
		sort(asteroids.begin(), asteroids.end());
		long m = mass;
		for (auto n : asteroids)
		{
			if (m < n)
				return false;
			m += n;
		}
		return true;
	}
};