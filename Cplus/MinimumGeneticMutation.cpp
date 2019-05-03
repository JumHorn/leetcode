#include<vector>
#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> visited;
		queue<string> *p=new queue<string>();
		queue<string> *q=new queue<string>();
		int res=0;
		p->push(start);
		visited.insert(start);
		while(!p->empty())
		{
			res++;
			while(!p->empty())
			{
				for(int i=0;i<(int)bank.size();i++)
				{
					if(visited.find(bank[i])!=visited.end())
						continue;
					int tmp=minMutation(p->front(),bank[i]);
					if(tmp==1)
					{
						tmp=minMutation(bank[i],end);
						if(tmp==0)
							return res;
						q->push(bank[i]);
						visited.insert(bank[i]);
					}
				}
				p->pop();
			}
			queue<string>* tmp=p;
			p=q;
			q=tmp;
		}
		return -1;
    }

	int minMutation(const string& l,const string& r)
	{
		int res=0,index=-1;
		while(++index<(int)l.size())
			if(l[index]!=r[index])
				res++;
		return res;
	}
};
