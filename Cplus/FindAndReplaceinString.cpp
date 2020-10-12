#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string findReplaceString(string S, vector<int> &indexes, vector<string> &sources, vector<string> &targets)
	{
		int N = indexes.size(), index = 0;
		vector<pair<int, int>> v;
		//sort indexes
		for (int i = 0; i < N; ++i)
			v.push_back({indexes[i], i});
		sort(v.begin(), v.end());
		string res;
		for (int i = 0; i < N; ++i)
		{
			res += S.substr(index, v[i].first - index);
			index = v[i].first;
			int j = v[i].second;
			if (S.compare(v[i].first, sources[j].length(), sources[j]) == 0)
			{
				res += targets[j];
				index += sources[j].length();
			}
		}
		return res + S.substr(index);
	}
};