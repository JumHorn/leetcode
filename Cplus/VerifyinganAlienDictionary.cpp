#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isAlienSorted(vector<string> &words, string order)
	{
		unordered_map<char, int> m; //{char, order}
		for (int i = 0; i < (int)order.size(); ++i)
			m[order[i]] = i;
		for (int i = 0; i < (int)words.size() - 1; ++i)
		{
			if (!alienCmp(words[i], words[i + 1], m))
				return false;
		}
		return true;
	}

	bool alienCmp(string &lhs, string &rhs, unordered_map<char, int> &order)
	{
		int N1 = lhs.size(), N2 = rhs.size(), i = 0;
		for (; i < N1 && i < N2; ++i)
		{
			if (lhs[i] != rhs[i])
				return order[lhs[i]] < order[rhs[i]];
		}
		return i == N1;
	}
};