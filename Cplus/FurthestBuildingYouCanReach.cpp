#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
	int furthestBuilding(vector<int> &heights, int bricks, int ladders)
	{
		int res = 0;
		priority_queue<int> q;
		for (int i = 1; i < (int)heights.size(); ++i)
		{
			if (heights[i - 1] < heights[i])
			{
				int h = heights[i] - heights[i - 1];
				if (bricks >= h)
				{
					bricks -= h;
					q.push(h);
				}
				else
				{
					if (ladders == 0)
						break;
					--ladders;
					if (!q.empty() && h < q.top())
					{
						int b = q.top();
						q.pop();
						bricks += b - h;
						q.push(h);
					}
				}
			}
			res = i;
		}
		return res;
	}
};