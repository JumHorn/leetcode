#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string shiftingLetters(string S, vector<int> &shifts)
	{
		int N = shifts.size();
		for (int i = N - 2; i >= 0; --i)
			shifts[i] = shifts[i] % 26 + shifts[i + 1] % 26;
		for (int i = 0; i < N; ++i)
			S[i] = (S[i] - 'a' + shifts[i]) % 26 + 'a';
		return S;
	}
};