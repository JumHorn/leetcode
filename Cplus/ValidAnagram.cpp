#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool isAnagram(string s, string t)
	{
		unordered_map<char, int> m1, m2;
		for (auto c : s)
			++m1[c];
		for (auto c : t)
			++m2[c];
		return m1 == m2;
	}
};