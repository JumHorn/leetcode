#include<vector>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
	int removeBoxes(vector<int>& boxes)
	{
		map<vector<int>,int> visited;
		return removeBoxes(boxes,visited);
	}

    int removeBoxes(vector<int>& boxes,map<vector<int>,int>& visited) {
		int res=0;
		for(int i=0;i<(int)boxes.size();)
		{
			int j=i+1;
			while(j<(int)boxes.size()&&boxes[i]==boxes[j])
				j++;
			vector<int> tmp(boxes);
			tmp.erase(tmp.begin()+i,tmp.begin()+j);
			if(visited.find(tmp)!=visited.end())
			{
				return visited[tmp];
			}
			res=max(res,(j-i)*(j-i)+removeBoxes(tmp));
			i=j;
		}		
		visited[boxes]=res;
		return res;
    }
};
