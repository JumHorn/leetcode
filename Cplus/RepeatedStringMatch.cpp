#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int repeatedStringMatch(string A, string B)
	{
		int Alen = A.size(), Blen = B.size();
		vector<int> kmp(Blen);
		for (int i = 1, j = 0; i < Blen; ++i)
		{
			while (j > 0 && B[j] != B[i])
				j = kmp[j - 1];
			if (B[j] == B[i])
				++j;
			kmp[i] = j;
		}

		for (int i = 0, j = 0; i < Alen; ++i)
		{
			while (j < Blen && A[(i + j) % Alen] == B[j])
				++j;
			if (j == Blen)
				return (i + j - 1) / Alen + 1;
			if (j > 0)
			{
				i += max(1, j - kmp[j - 1]) - 1; //-1 use to cancel out next ++i
				j = kmp[j - 1];
			}
		}
		return -1;
	}
};