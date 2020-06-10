#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int scheduleCourse(vector<vector<int>> &courses)
	{
		if (courses.empty())
			return 0;
		sort(courses.begin(), courses.end(), *this);
		priority_queue<int> q;
		int time = courses[0][0];
		q.push(time);
		for (int i = 1; i < (int)courses.size(); i++)
		{
			if (time + courses[i][0] <= courses[i][1])
			{
				time += courses[i][0];
				q.push(courses[i][0]);
			}
			else
			{
				if (courses[i][0] < q.top())
				{
					time += courses[i][0] - q.top();
					q.pop();
					q.push(courses[i][0]);
				}
			}
		}
		return q.size();
	}

	bool operator()(vector<int> &lhs, vector<int> &rhs)
	{
		return lhs[1] < rhs[1];
	}
};