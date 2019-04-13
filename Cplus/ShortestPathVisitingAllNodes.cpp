#include<vector>
#include<queue>
#include<set>
using namespace std;

class Solution {
public:
    int shortestPathLength(vector<vector<int> >& graph) {
        if(graph.empty()||graph[0].empty())
            return 0;
		int n=(1<<graph.size())-1;
		queue<pair<int,int> > *q=new queue<pair<int,int> >();
		queue<pair<int,int> > *p=new queue<pair<int,int> >();
		set<pair<int,int> > visited;
        for(int i=0;i<(int)graph.size();i++)
			if((graph[i].size()&1)==1)
			{
				visited.insert(pair<int,int>(i,1<<i));
				q->push(pair<int,int>(i,1<<i));
			}
		if(q->empty())
			for(int i=0;i<(int)graph.size();i++)
			{
				visited.insert(pair<int,int>(i,1<<i));
				q->push(pair<int,int>(i,1<<i));
			}
		int res=0;
		while(true)
		{
			while(!q->empty())
			{
				if(q->front().second==n)
					return res;
				for(int i=graph[q->front().first].size()-1;i>=0;i--)
				{
					pair<int,int> tmp(graph[q->front().first][i],q->front().second|(1<<graph[q->front().first][i]));
					if(visited.find(tmp)==visited.end())
					{
						visited.insert(tmp);
						p->push(tmp);
					}
				}
				q->pop();
			}
			res++;
			queue<pair<int,int> > *tmp=p;
			p=q;
			q=tmp;
		}
		delete p;
		delete q;
		return res;
	}
};
