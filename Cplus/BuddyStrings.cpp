#include <string>
using namespace std;

class Solution
{
public:
	bool buddyStrings(string A, string B)
	{
		if (A.size() != B.size())
			return false;
		int hash[26] = {0}, same = 1;
		int index[3], diff = 0, N = A.size();
		for (int i = 0; i < N && diff <= 2; ++i)
		{
			if (++hash[A[i] - 'a'] > same)
				same = hash[A[i] - 'a'];
			if (A[i] != B[i])
				index[diff++] = i;
		}
		return (diff == 0 && same > 1) ||
			   (diff == 2 &&
				A[index[0]] == B[index[1]] &&
				A[index[1]] == B[index[0]]);
	}
};