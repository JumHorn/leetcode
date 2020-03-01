#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
	{
		vector<vector<string>> res(searchWord.size());
		vector<string> suggest;
		for (int k = 0; k < (int)searchWord.size(); k++)
		{
			suggest.clear();
			for (int i = 0; i < (int)products.size(); i++)
				if (k < (int)products[i].length() && products[i][k] == searchWord[k])
				{
					suggest.push_back(products[i]);
					push_heap(suggest.begin(), suggest.end(), greater<string>());
				}
			int n = suggest.size();
			for (int i = 0; i < 3 && n - i > 0; i++)
			{
				pop_heap(suggest.begin(), suggest.begin() + n - i, greater<string>());
				res[k].push_back(*(suggest.begin() + n - i - 1));
			}
			swap(products, suggest);
		}
		return res;
	}
};