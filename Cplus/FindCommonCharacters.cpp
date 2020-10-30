#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> commonChars(vector<string> &A)
	{
		vector<int> hash(26);
		charCount(A[0], hash);
		for (int i = 1; i < (int)A.size(); ++i)
		{
			vector<int> count(26);
			charCount(A[i], count);
			minArr(hash, count);
		}
		vector<string> res;
		for (int i = 0; i < 26; ++i)
		{
			while (--hash[i] >= 0)
				res.push_back(string(1, 'a' + i));
		}
		return res;
	}

	void charCount(string &s, vector<int> &hash)
	{
		for (auto c : s)
			++hash[c - 'a'];
	}

	void minArr(vector<int> &lhs, vector<int> &rhs)
	{
		for (int i = 0; i < (int)lhs.size(); ++i)
			lhs[i] = min(lhs[i], rhs[i]);
	}
};