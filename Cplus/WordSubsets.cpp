#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> wordSubsets(vector<string> &A, vector<string> &B)
	{
		vector<int> count(26);
		for (auto &str : B)
		{
			vector<int> v(26);
			for (auto c : str)
			{
				int index = c - 'a';
				count[index] = max(++v[index], count[index]);
			}
		}

		vector<string> res;
		for (auto &str : A)
		{
			if (checkString(str, count))
				res.push_back(str);
		}
		return res;
	}

	bool checkString(string &s, vector<int> &count)
	{
		vector<int> v(26);
		for (auto c : s)
			++v[c - 'a'];
		for (int i = 0; i < 26; ++i)
		{
			if (v[i] < count[i])
				return false;
		}
		return true;
	}
};