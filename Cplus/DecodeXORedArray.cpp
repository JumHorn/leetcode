#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> decode(vector<int> &encoded, int first)
	{
		vector<int> res = {first};
		for (auto n : encoded)
			res.push_back(res.back() ^ n);
		return res;
	}
};