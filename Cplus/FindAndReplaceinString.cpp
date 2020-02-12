#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets)
	{
		if (indexes.empty())
			return S;
		string res;
		int n = indexes.size();
		//sort indexes
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - 1 - i; j++)
			{
				if (indexes[j] > indexes[j + 1])
				{
					swap(indexes[j], indexes[j + 1]);
					swap(sources[j], sources[j + 1]);
					swap(targets[j], targets[j + 1]);
				}
			}
		}

		if (indexes[0] != 0)
			res = S.substr(0, indexes[0]);
		for (int i = 0; i < n; i++)
		{
			if (S.substr(indexes[i], sources[i].size()) == sources[i])
			{
				res += targets[i];
				if (i < n - 1)
				{
					if (indexes[i + 1] > indexes[i] + (int)sources[i].size())
						res += S.substr(indexes[i] + sources[i].size(), indexes[i + 1] - indexes[i] - sources[i].size());
				}
				else
				{
					if ((int)S.size() > indexes[i] + (int)sources[i].size())
						res += S.substr(indexes[i] + (int)sources[i].size());
				}
			}
			else
			{
				if (i < n - 1)
				{
					res += S.substr(indexes[i], indexes[i + 1] - indexes[i]);
				}
				else
				{
					res += S.substr(indexes[i]);
				}
			}
		}
		return res;
	}
};
