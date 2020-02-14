#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	vector<string> wordSubsets(vector<string> &A, vector<string> &B)
	{
		vector<int> v(26);
		for (int i = 0; i < (int)B.size(); i++)
		{
			vector<int> tmp(26);
			for (int j = 0; j < (int)B[i].length(); j++)
			{
				int index = B[i][j] - 'a';
				if (++tmp[index] > v[index])
					v[index] = tmp[index];
			}
		}

		vector<string> res;
		for (int i = 0; i < (int)A.size(); i++)
		{
			if (checkString(A[i], v))
				res.push_back(A[i]);
		}
		return res;
	}

	bool checkString(string &s, vector<int> &v)
	{
		vector<int> tmp(26);
		for (int i = 0; i < (int)s.length(); i++)
			++tmp[s[i] - 'a'];
		for (int i = 0; i < 26; i++)
			if (tmp[i] < v[i])
				return false;
		return true;
	}
};