#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int> >& graph) {
        if(graph.empty()||graph[0].empty())
            return 0;
		queue<pair<int,unordered_set<int> > > *q=new queue<pair<int,unordered_set<int> > >();
		queue<pair<int,unordered_set<int> > > *p=new queue<pair<int,unordered_set<int> > >();
        for(int i=0;i<(int)graph.size();i++)
			if((graph[i].size()&1)==1)
			{
				unordered_set<int> s;
				s.insert(i);
				q->push(pair<int,unordered_set<int> >(i,s));
			}
		if(q->empty())
		{
			unordered_set<int> s;
			s.insert(0);
			q->push(pair<int,unordered_set<int> >(0,s));
		}
		int res=0;
		while(true)
		{
			while(!q->empty())
			{
				if(q->front().second.size()==graph.size())
					return res;
				for(int i=graph[q->front().first].size()-1;i>=0;i--)
				{
					pair<int,unordered_set<int> > tmp=q->front();
					tmp.second.insert(graph[q->front().first][i]);
					tmp.first=graph[q->front().first][i];
					p->push(tmp);
				}
				q->pop();
			}
            res++;
			queue<pair<int,unordered_set<int> > > *tmp=q;
			q=p;
			p=tmp;
		}
		delete p;
		delete q;
		return res;
	}
};
