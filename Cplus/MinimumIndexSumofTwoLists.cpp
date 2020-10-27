#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
	{
		int indexsum = INT_MAX;
		vector<string> res;
		unordered_map<string, int> m; //{restaurant,index}
		for (int i = 0; i < (int)list1.size(); ++i)
			m[list1[i]] = i;
		for (int i = 0; i < (int)list2.size(); ++i)
		{
			if (m.find(list2[i]) != m.end())
			{
				if (m[list2[i]] + i <= indexsum)
				{
					if (m[list2[i]] + i < indexsum)
					{
						indexsum = m[list2[i]] + i;
						res.clear();
					}
					res.push_back(list2[i]);
				}
			}
		}
		return res;
	}
};