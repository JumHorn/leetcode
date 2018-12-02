#include<vector>
#include<string>
#include<list>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
		if(target=="0000")
			return 0;
		if(find(deadends.begin(),deadends.end(),"0000")!=deadends.end())
			return -1;
		list<string> bfs;
		list<string> visited;
		bfs.push_back("0000");
		visited.push_back("0000");
		int res=0;
		while(bfs.size()!=0)
		{
			res++;
			int size=bfs.size();
			for(int i=0;i<size;i++)
			{
				string t=*bfs.begin();
				bfs.erase(bfs.begin());
				for(int i=0;i<4;i++)
				{
					string tmp=t;
					tmp[i]=(tmp[i]+1)>9+'0'?'0':(tmp[i]+1);
					if(tmp==target)
						return res;
					if(find(visited.begin(),visited.end(),tmp)==visited.end()&&find(deadends.begin(),deadends.end(),tmp)==deadends.end())
					{
						bfs.push_back(tmp);
						visited.push_back(tmp);
					}
					tmp=t;
					tmp[i]=(tmp[i]-1)<'0'?'9':(tmp[i]-1);
					if(tmp==target)
						return res;
					if(find(visited.begin(),visited.end(),tmp)==visited.end()&&find(deadends.begin(),deadends.end(),tmp)==deadends.end())
					{
						bfs.push_back(tmp);
						visited.push_back(tmp);
					}
				}
			}
		}
		return -1;
    }
};
