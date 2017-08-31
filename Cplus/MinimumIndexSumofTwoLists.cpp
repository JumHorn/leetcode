#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
	public:
		vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
			int sumindex = INT_MAX;
			int temp;
			string result;
			vector<string> ret;
			for(vector<string>::iterator iter=list1.begin();iter!=list1.end();iter++)
			{
				vector<string>::iterator it=find(list2.begin(),list2.end(),*iter);
				if(it==list2.end())
				{
					continue;
				}
				temp=distance(list2.begin(),it)+distance(list1.begin(),iter);
				if(temp<sumindex)
				{
					sumindex=temp;
					ret.clear();
					ret.push_back(*it);
					continue;
				}
				if(temp==sumindex)
				{
					ret.push_back(*it);
				}
			}
			return ret;
		}
};

int main()
{

}
