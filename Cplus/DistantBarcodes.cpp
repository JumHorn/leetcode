#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> rearrangeBarcodes(vector<int> &barcodes)
	{
		int N = barcodes.size();
		unordered_map<int, int> m; //{val,count}
		vector<int> res(N);
		int mostvalue = 0;
		for (auto n : barcodes)
		{
			if (++m[n] > m[mostvalue])
				mostvalue = n;
		}
		int i = 0;
		for (; --m[mostvalue] >= 0; i += 2)
			res[i] = mostvalue;
		for (auto n : m)
		{
			if (n.second <= 0)
				continue;
			while (--n.second >= 0)
			{
				if (i >= N)
					i = 1;
				res[i] = n.first;
				i += 2;
			}
		}
		return res;
	}
};