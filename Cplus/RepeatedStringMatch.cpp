#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	int repeatedStringMatch(string A, string B)
	{
		int Alen = A.size(), Blen = B.size();
		for (int i = 0; i < Alen; ++i)
		{
			int j = 0;
			while (j < Blen && A[(i + j) % Alen] == B[j])
				++j;
			if (j == Blen)
				return (i + j - 1) / Alen + 1;
		}
		return -1;
	}
};