#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int scheduleCourse(vector<vector<int> >& courses) {
		if(courses.empty())
			return 0;
		sort(courses.begin(),courses.end(),*this);
		priority_queue<vector<int> > q;
		q.push(courses.front());
		int start=courses.front().front();
		for(int i=1;i<(int)courses.size();i++)
		{
			if(start+courses[i][0]<=courses[i][1])
			{
				start+=courses[i][0];
				q.push(courses[i]);
			}
			else
			{
				if(courses[i][0]<q.top()[0])
				{
					start+=courses[i][0]-q.top()[0];
					q.pop();
                    q.push(courses[i]);
				}
			}
		}
		return q.size();
    }

	bool operator()(vector<int>& lhs,vector<int>& rhs)
	{
		return lhs[1]<rhs[1];
	}
};
