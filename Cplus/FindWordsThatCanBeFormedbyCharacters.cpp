#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int countCharacters(vector<string> &words, string chars)
	{
		vector<int> count(26);
		int res = 0;
		for (auto c : chars)
			++count[c - 'a'];
		for (auto &word : words)
		{
			vector<int> hash(26);
			for (auto c : word)
				++hash[c - 'a'];
			if (arrLessThan(count, hash))
				res += word.length();
		}
		return res;
	}

	bool arrLessThan(vector<int> &count, vector<int> &hash)
	{
		for (int i = 0; i < (int)hash.size(); ++i)
		{
			if (count[i] < hash[i])
				return false;
		}
		return true;
	}
};