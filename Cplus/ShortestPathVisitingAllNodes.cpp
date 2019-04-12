#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int> >& graph) {
		queue<pair<int,unordered_set<int> > > *q=new queue<pair<int,unordered_set<int> > >();
		queue<pair<int,unordered_set<int> > > *p=new queue<pair<int,unordered_set<int> > >();
        for(int i=0;i<(int)graph.size();i++)
			if((graph[i].size()&1)==1)
			{
				unordered_set<int> s;
				s.insert(i);
				q->push(pair<int,unordered_set<int> >(i,s));
			}
		int res=0;
		while(true)
		{
			res++;
			while(!q->empty())
			{
				if(q->front().second.size()==graph.size())
					return res;
				for(int i=0;i<(int)graph[q->front().first].size();i++)
				{
					pair<int,unordered_set<int> > tmp=q->front();
					tmp.second.insert(graph[q->front().first][i]);
					tmp.first=i;
					p->push(tmp);
				}
				q->pop();
			}
			queue<pair<int,unordered_set<int> > > *tmp=q;
			q=p;
			p=tmp;
		}
		return res;
	}
};
