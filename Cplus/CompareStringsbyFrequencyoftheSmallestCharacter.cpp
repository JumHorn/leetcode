#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words)
	{
		vector<int> freq;
		for (auto &word : words)
			freq.push_back(smallestFrequency(word));
		sort(freq.begin(), freq.end());
		vector<int> res;
		int N = freq.size();
		for (auto &query : queries)
		{
			int f = smallestFrequency(query);
			int larger = upper_bound(freq.begin(), freq.end(), f) - freq.begin();
			res.push_back(N - larger);
		}
		return res;
	}

	int smallestFrequency(string &word)
	{
		map<char, int> m; //{char,count}
		for (auto c : word)
			++m[c];
		return m.begin()->second;
	}
};