#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> removeAnagrams(vector<string> &words)
	{
		vector<string> dup(words);
		for (auto &str : dup)
			sort(str.begin(), str.end());
		int N = words.size();
		vector<int> index;
		for (int i = 0; i < N; ++i)
		{
			if (index.empty() || dup[index.back()] != dup[i])
				index.push_back(i);
		}
		vector<string> res;
		for (auto n : index)
			res.push_back(words[n]);
		return res;
	}
};