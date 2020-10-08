#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	int openLock(vector<string> &deadends, string target)
	{
		if (target == "0000")
			return 0;
		unordered_set<string> dead(deadends.begin(), deadends.end());
		if (dead.find("0000") != dead.end())
			return -1;
		unordered_set<string> seen;
		queue<string> q;
		q.push("0000");
		seen.insert("0000");
		int res = 0;
		while (q.size() != 0)
		{
			++res;
			int size = q.size();
			while (--size >= 0)
			{
				for (int i = 0; i < 4; ++i)
				{
					string lock = q.front();
					// lock[i] = (lock[i] - '0' + 1) % 10 + '0';
					// lock[i] = (lock[i] - '0' + 10 - 2) % 10 + '0';
					for (int j = 0; j < 2; ++j)
					{
						lock[i] = (lock[i] - '0' + j * 7 + 1) % 10 + '0';
						if (lock == target)
							return res;
						if (seen.find(lock) == seen.end() && dead.find(lock) == dead.end())
						{
							seen.insert(lock);
							q.push(lock);
						}
					}
				}
				q.pop();
			}
		}
		return -1;
	}
};