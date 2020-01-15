#include <map>
using namespace std;

class Solution
{
public:
	double soupServings(int N)
	{
		if (N >= 5000)
			return 1;
		map<pair<int, int>, double> m;
		return recursive(N, N, m);
	}

	double recursive(int A, int B, map<pair<int, int>, double>& m)
	{
		if (A <= 0 && B <= 0)
			return 0.5;
		if (A <= 0)
			return 1;
		if (B <= 0)
			return 0;
		if (m.find({A, B}) != m.end())
			return m[{A, B}];
		double res = 0.25 * (recursive(A - 100, B, m) + recursive(A - 75, B - 25, m) + recursive(A - 50, B - 50, m) + recursive(A - 25, B - 75, m));
		m[{A, B}] = res;
		return res;
	}
};

