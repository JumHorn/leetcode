#include <string>
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
		for (int i = 0; i < 26; ++i)
		{
			if ((count1[i] != 0 && count2[i] == 0) ||
				(count1[i] == 0 && count2[i] != 0))
				return false;
		}
		sort(count1.begin(), count1.end());
		sort(count2.begin(), count2.end());
		return count1 == count2;
	}
};