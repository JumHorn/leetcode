#include<vector>
#include<queue>
using namespace std;

class Solution {
	struct PairsSum
	{
		int p0;
		int p1;
		PairsSum(int v0,int v1):p0(v0),p1(v1)
		{}
		bool operator<(const PairsSum& others) const
		{
			return p0+p1<=others.p0+others.p1;
		}
	};
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		priority_queue<PairsSum> q;
		for(int i=0;i<(int)nums1.size();i++)
			for(int j=0;j<(int)nums2.size();j++)
			{
				if((int)q.size()<k)
				{
					q.push(PairsSum(nums1[i],nums2[j]));
					continue;
				}
				PairsSum tmp(nums1[i],nums2[j]);
				if(q.top()<tmp)
					break;
				q.pop();
				q.push(tmp);
			}
		k=k>(int)q.size()?q.size():k;
		vector<vector<int>> res(k);
		for(int i=0;i<k;i++)
        {
			res[k-i-1]={q.top().p0,q.top().p1};
            q.pop();
        }
		return res;	
    }
};
