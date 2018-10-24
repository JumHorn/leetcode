#include<vector>
#include<map>
using namespace std;
//  For all the node
//  traverse the graph to find the value appeared three times 
//  if we can not find one,return the last one
//  If we can, return the value last appeared
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int> >& edges) {
		vector<vector<int> >::iterator iter=edges.begin(),tmp;
		map<int,int> statistics;
		while(true)
		{
			int flag=2;
			for(;iter!=edges.end();iter++)
			{
				if(++statistics[iter->at(0)]==3)
				{
					flag=0;
					++statistics[iter->at(1)];
					break;
				}
				if(++statistics[iter->at(1)]==3)
				{
					flag=1;
					break;
				}
			}
			if(flag!=2)
			{
				for(tmp=iter;tmp!=edges.begin()-1;tmp--)
				{
					if(tmp->at(0)==iter->at(flag)&&statistics[tmp->at(1)]==2)
					{
						return *tmp;
					}
					if(tmp->at(1)==iter->at(flag)&&statistics[tmp->at(0)]==2)
					{
						return *tmp;
					}
				}
				iter++;
			}
			else
			{
				break;
			}
		}
		return *(iter-1);
    }
};
