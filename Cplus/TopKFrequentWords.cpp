#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> topKFrequent(vector<string> &words, int k)
	{
		unordered_map<string, int> freq;
		for (auto &word : words)
			++freq[word];
		auto f = [&](pair<int, string> &lhs, pair<int, string> &rhs) {
			if (lhs.first != rhs.first)
				return lhs.first < rhs.first;
			return lhs.second > rhs.second;
		};
		priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(f)> q(f); //{freq,str}
		for (auto &iter : freq)
			q.push({iter.second, iter.first});
		vector<string> res;
		for (int i = 0; i < k; ++i)
		{
			res.push_back(q.top().second);
			q.pop();
		}
		return res;
	}
};