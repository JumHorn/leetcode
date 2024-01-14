#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> beautifulIndices(string s, string a, string b, int k)
	{
		int N = s.size(), A = a.size(), B = b.size();
		auto kmp = [&](string &str, vector<int> &kmptable)
		{
			for (int i = 1, j = 0; i < (int)str.size(); ++i)
			{
				while (j > 0 && str[j] != str[i])
					j = kmptable[j - 1];
				if (str[j] == str[i])
					++j;
				kmptable[i] = j;
			}
		};
		vector<int> ka(A), kb(B);
		kmp(a, ka);
		kmp(b, kb);
		vector<int> apos, bpos;
		findAll(s, a, ka, apos);
		findAll(s, b, kb, bpos);
		vector<int> res;
		if (bpos.empty())
			return res;
		int i = 0, M = bpos.size();
		for (auto n : apos)
		{
			while (i < M && bpos[i] < n && n - bpos[i] > k)
				++i;
			if (i == M)
				break;
			if (abs(n - bpos[i]) <= k)
				res.push_back(n);
		}
		return res;
	}

	void findAll(string &s, string &str, vector<int> &kmp, vector<int> &pos)
	{
		int M = s.size(), N = str.size();
		for (int i = 0, j = 0; i < M;)
		{
			if (s[i] == str[j])
			{
				++i;
				++j;
			}
			else
				j > 0 ? j = kmp[j - 1] : ++i;

			if (j == N)
			{
				pos.push_back(i - j);
				j = kmp[j - 1];
			}
		}
	}
};