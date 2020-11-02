#include <algorithm>
#include <vector>
using namespace std;

/*
       start ---------- n
1 --------------------- n
1 --------------------- n
1 --------------- end

            start ----- n
1 --------------------- n
1 --------------------- n
1 ----- end

we only care about start end
1. start < end return [start,end]
2. start > end return [1,end] and  [start,n]
*/

class Solution
{
public:
	vector<int> mostVisited(int n, vector<int> &rounds)
	{
		vector<int> res;
		for (int i = rounds[0]; i <= rounds.back(); ++i)
			res.push_back(i);
		if (!res.empty())
			return res;
		for (int i = 1; i <= rounds.back(); ++i)
			res.push_back(i);
		for (int i = rounds[0]; i <= n; ++i)
			res.push_back(i);
		return res;
	}
};