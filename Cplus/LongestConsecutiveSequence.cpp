#include <vector>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{
		unordered_map<int, int> head, tail;
		unordered_set<int> seen;
		int res = 0;
		for (auto n : nums)
		{
			if (seen.find(n) != seen.end())
				continue;
			seen.insert(n);
			if (head.find(n + 1) != head.end() && tail.find(n - 1) != tail.end())
			{
				head[tail[n - 1]] = head[n + 1];
				tail[head[n + 1]] = tail[n - 1];
				res = max(res, head[tail[n - 1]] - tail[n - 1] + 1);
			}
			else if (head.find(n + 1) != head.end())
			{
				head[n] = head[n + 1];
				tail[head[n + 1]] = n;
				res = max(res, head[n] - n + 1);
			}
			else if (tail.find(n - 1) != tail.end())
			{
				tail[n] = tail[n - 1];
				head[tail[n - 1]] = n;
				res = max(res, n - tail[n] + 1);
			}
			else
			{
				head[n] = n;
				tail[n] = n;
				res = max(res, 1);
			}
		}
		return res;
	}
};