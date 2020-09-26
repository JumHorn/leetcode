#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string frequencySort(string s)
	{
		vector<pair<int, char>> hash(256); //{count,character}
		for (int i = 0; i < 256; ++i)
			hash[i].second = i;
		for (auto c : s)
			++hash[(int)c].first;
		sort(hash.begin(), hash.end(), greater<pair<int, char>>());
		string res;
		for (int i = 0; i < 256; ++i)
			res += string(hash[i].first, hash[i].second);
		return res;
	}
};