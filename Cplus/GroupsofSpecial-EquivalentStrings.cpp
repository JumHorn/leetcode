#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSpecialEquivGroups(vector<string> &A)
	{
		unordered_set<string> s;
		for (auto str : A)
			s.insert(normaliseWord(str));
		return s.size();
	}

	string normaliseWord(const string &word) //encode the odd/even indexed element
	{
		string res(52, 'a');
		for (int i = 0; i < (int)word.size(); ++i)
			++res[word[i] - 'a' + 26 * (i & 1)];
		return res;
	}
};