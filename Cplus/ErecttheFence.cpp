#include <vector>
using namespace std;

class Solution
{
public:
	vector<vector<int>> outerTrees(vector<vector<int>> &points)
	{
		int n = points.size();
		if (n <= 3)
			return points;
		int origin = 0;
		for (int i = 0; i < n; i++)
		{
			if (points[i][0] < points[origin][0])
				origin = i;
		}
		int index = origin;
		vector<int> seen(n);
		do
		{
			seen[index] = 1;
			int nextindex = (index + 1) % n;
			for (int i = 0; i < n; i++)
			{
				if (crossProduct(points[index], points[i], points[nextindex]) > 0)
					nextindex = i;
			}
			for (int i = 0; i < n; i++)
			{
				if (i != index && i != nextindex)
				{
					int cross = crossProduct(points[index], points[i], points[nextindex]);
					if (cross == 0 && between(points[index], points[i], points[nextindex]))
						seen[i] = 1;
				}
			}
			index = nextindex;
		} while (index != origin);
		vector<vector<int>> res;
		for (int i = 0; i < n; i++)
		{
			if (seen[i] == 1)
				res.push_back(points[i]);
		}
		return res;
	}

	bool between(vector<int> &pointA, vector<int> &pointB, vector<int> &pointC)
	{
		bool x = ((pointB[0] >= pointA[0] && pointB[0] <= pointC[0]) || (pointB[0] <= pointA[0] && pointB[0] >= pointC[0]));
		bool y = ((pointB[1] >= pointA[1] && pointB[1] <= pointC[1]) || (pointB[1] <= pointA[1] && pointB[1] >= pointC[1]));
		return x && y;
	}

	int crossProduct(vector<int> &pointA, vector<int> &pointB, vector<int> &pointC)
	{
		int x1 = pointB[0] - pointA[0];
		int y1 = pointB[1] - pointA[1];
		int x2 = pointC[0] - pointA[0];
		int y2 = pointC[1] - pointA[1];
		return x1 * y2 - x2 * y1;
	}
};