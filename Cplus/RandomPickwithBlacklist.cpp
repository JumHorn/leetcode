#include <cmath> // for rand
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(int N, vector<int> &blacklist)
	{
		for (auto black : blacklist)
			blackmap[black] = black;
		size = N - blacklist.size();
		--N;
		for (auto black : blacklist)
		{
			if (black < size)
			{
				while (blackmap.find(N) != blackmap.end())
					--N;
				blackmap[black] = N--;
			}
		}
	}

	int pick()
	{
		int res = rand() % size;
		if (blackmap.find(res) == blackmap.end())
			return res;
		return blackmap[res];
	}

private:
	unordered_map<int, int> blackmap;
	int size;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */