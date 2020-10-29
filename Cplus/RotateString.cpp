#include <string>
using namespace std;

class Solution
{
public:
	bool rotateString(string A, string B)
	{
		if (A.length() != B.length())
			return false;
		if (A == B)
			return true;
		int N = A.length();
		for (int i = 0; i < N; ++i)
		{
			if (A.compare(i, N - i, B, 0, N - i) == 0 && A.compare(0, i, B, N - i, i) == 0)
				return true;
		}
		return false;
	}
};