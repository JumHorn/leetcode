#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string fractionAddition(string expression)
	{
		stringstream expr(expression);
		int A = 0, B = 1, a, b;
		char _; // '/'
		while (expr >> a >> _ >> b)
		{
			A = A * b + a * B;
			B *= b;
			int g = abs(gcd(A, B));
			A /= g;
			B /= g;
		}
		return to_string(A) + '/' + to_string(B);
	}

	int gcd(int x, int y)
	{
		if (x == 0)
			return y;
		return gcd(y % x, x);
	}
};