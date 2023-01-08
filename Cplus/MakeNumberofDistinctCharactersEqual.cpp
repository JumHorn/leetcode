#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	bool isItPossible(string word1, string word2)
	{
		vector<int> v1(26), v2(26);
		for (auto c : word1)
			++v1[c - 'a'];
		for (auto c : word2)
			++v2[c - 'a'];
		for (int i = 0; i < 26; ++i)
		{
			if (v1[i] <= 0)
				continue;
			for (int j = 0; j < 26; ++j)
			{
				if (v2[j] > 0)
				{
					--v1[i];
					--v2[j];
					++v1[j];
					++v2[i];
					if (check(v1, v2))
						return true;
					++v1[i];
					--v1[j];
					++v2[j];
					--v2[i];
				}
			}
		}
		return false;
	}

	bool check(vector<int> &v1, vector<int> &v2)
	{
		int d1 = 0, d2 = 0;
		for (auto n : v1)
		{
			if (n > 0)
				++d1;
		}
		for (auto n : v2)
		{
			if (n > 0)
				++d2;
		}
		return d1 == d2;
	}
};