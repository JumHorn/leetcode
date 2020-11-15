#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	bool closeStrings(string word1, string word2)
	{
		if (word1.length() != word2.length())
			return false;
		vector<int> count1(26), count2(26);
		int N = word1.length();
		for (int i = 0; i < N; ++i)
		{
			++count1[word1[i] - 'a'];
			++count2[word2[i] - 'a'];
		}
		if (count1 == count2)
			return true;
		for (int i = 0; i < 26; ++i)
		{
			if (count1[i] != count2[i] && (count1[i] == 0 || count2[i] == 0))
				return false;
		}
		unordered_map<int, int> m1, m2;
		for (auto n : count1)
			++m1[n];
		for (auto n : count2)
			++m2[n];
		return m1 == m2;
	}
};