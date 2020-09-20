#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findRepeatedDnaSequences(string s)
	{
		unordered_set<string> s1, s2;
		for (int i = 0; i < (int)s.length() - 9; ++i)
		{
			string str = s.substr(i, 10);
			if (s1.find(str) == s1.end())
				s1.insert(str);
			else
				s2.insert(str);
		}

		return vector<string>(s2.begin(), s2.end());
	}
};