#include<vector>
#include<string>
#include<unordered_set>
#include<list>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
		if(target=="0000")
			return 0;
		if(find(deadends.begin(),deadends.end(),"0000")!=deadends.end())
			return -1;
		unordered_set<string> dds(deadends.begin(), deadends.end());
        unordered_set<string> visited;
		list<string> bfs;
		bfs.push_back("0000");
		visited.insert("0000");
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
					if(visited.find(tmp)==visited.end()&&dds.find(tmp)==dds.end())
					{
						bfs.push_back(tmp);
						visited.insert(tmp);
					}
					tmp=t;
					tmp[i]=(tmp[i]-1)<'0'?'9':(tmp[i]-1);
					if(tmp==target)
						return res;
					if(visited.find(tmp)==visited.end()&&dds.find(tmp)==dds.end())
					{
						bfs.push_back(tmp);
						visited.insert(tmp);
					}
				}
			}
		}
		return -1;
    }
};
