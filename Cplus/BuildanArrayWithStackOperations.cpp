#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> buildArray(vector<int>& target, int n)
	{
		vector<string> res;
		int last = target.back();
		for (int i = 1, j = 0; i <= last; i++)
		{
			if (i == target[j])
			{
				j++;
				res.push_back("Push");
			}
			else
			{
				res.push_back("Push");
				res.push_back("Pop");
			}
		}
		return res;
	}
};
