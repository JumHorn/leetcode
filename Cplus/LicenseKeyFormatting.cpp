#include <string>
using namespace std;

class Solution
{
public:
	string licenseKeyFormatting(string S, int K)
	{
		int N = 0;
		for (int i = 0; i < (int)S.length(); ++i)
		{
			if (S[i] != '-')
				S[N++] = toupper(S[i]);
		}
		string res = S.substr(0, N % K);
		for (int i = 0; i < N / K; ++i)
			res += (res.empty() ? "" : "-") + S.substr(N % K + K * i, K);
		return res;
	}
};