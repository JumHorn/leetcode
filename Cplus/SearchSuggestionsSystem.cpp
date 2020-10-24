#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
	{
		sort(products.begin(), products.end());
		auto it = products.begin();
		vector<vector<string>> res;
		string cur;
		for (auto c : searchWord)
		{
			cur.push_back(c);
			vector<string> suggested;
			it = lower_bound(it, products.end(), cur);
			for (auto iter = it; iter - it < 3 && iter != products.end(); ++iter)
			{
				if (iter->compare(0, cur.length(), cur) != 0)
					break;
				suggested.push_back(*iter);
			}
			res.push_back(suggested);
		}
		return res;
	}
};