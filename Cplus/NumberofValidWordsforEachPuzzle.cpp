#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
	{
		int N = puzzles.size();
		vector<int> res(N);
		unordered_map<int, int> m; //{mask,count}
		for (auto &word : words)
		{
			int mask = 0;
			for (auto c : word)
				mask |= (1 << (c - 'a'));
			++m[mask];
		}
		for (int i = 0; i < N; ++i)
		{
			int mask = 0;
			for (auto c : puzzles[i])
				mask |= (1 << (c - 'a'));
			for (int submask = mask; submask != 0; submask = ((submask - 1) & mask)) //loop for all submask
			{
				if ((submask & (1 << (puzzles[i][0] - 'a'))) != 0 && m.count(submask) != 0)
					res[i] += m[submask];
			}
		}
		return res;
	}
};