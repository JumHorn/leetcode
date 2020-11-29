#include <string>
#include <vector>
using namespace std;

class CombinationIterator
{
public:
	CombinationIterator(string characters, int combinationLength) : s(characters)
	{
		len = combinationLength;
		mask = (1 << characters.length()) - 1;
	}

	string next()
	{
		hasNext();
		string res;
		int N = s.length();
		for (int i = 0; i < N; ++i)
		{
			if (mask & (1 << (N - i - 1)))
				res.push_back(s[i]);
		}
		--mask;
		return res;
	}

	bool hasNext()
	{
		while (mask > 0 && bitCount(mask) != len)
			--mask;
		return mask != 0;
	}

private:
	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}

private:
	int mask;
	int len;
	string &s;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */