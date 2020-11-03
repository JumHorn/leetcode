#include <queue>
#include <vector>
using namespace std;

struct Element
{
	int val;
	int row;
	int column;

	Element(int val, int r, int c) : val(val), row(r), column(c)
	{
	}
};

struct Comp
{
	bool operator()(const Element &lhs, const Element &rhs)
	{
		return lhs.val > rhs.val;
	}
};

class Solution
{
public:
	vector<int> smallestRange(vector<vector<int>> &nums)
	{
		priority_queue<Element, vector<Element>, Comp> q;
		int n = nums.size();
		int maxval = INT_MIN;
		for (int i = 0; i < n; ++i)
		{
			maxval = max(maxval, nums[i][0]);
			q.push({nums[i][0], i, 0});
		}
		vector<int> res = {q.top().val, maxval};
		int range = maxval - q.top().val;
		while (q.top().column + 1 < (int)nums[q.top().row].size())
		{
			auto ele = q.top();
			q.pop();
			++ele.column;
			ele.val = nums[ele.row][ele.column];
			maxval = max(maxval, ele.val);
			q.push(ele);
			if (maxval - q.top().val < range)
			{
				range = maxval - q.top().val;
				res = {q.top().val, maxval};
			}
		}
		return res;
	}
};