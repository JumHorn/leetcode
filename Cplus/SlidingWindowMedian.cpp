#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		multiset<int> s;        
		vector<double> res(nums.size()-k+1);
		for(int i=0;i<k;i++)
			s.insert(nums[i]);
		multiset<int>::iterator iter=s.begin();
		advance(iter,k/2);
		if(k%2==1)
		{
			res[0]=*iter;
			for(int i=1;i<(int)res.size();i++)
			{
				int left=nums[i-1];
				int right=nums[i+k-1];
				if(left!=*iter)
					s.erase(s.find(left));
				else
				{
					s.erase(iter);
					s.insert(right);
					iter=s.begin();
					advance(iter,k/2);
					res[i]=*iter;
					continue;
				}
				s.insert(right);
				if((left<=res[i-1]&&right<=res[i-1])||(left>=res[i-1]&&right>=res[i-1]))
					res[i]=*iter;
				else if(left<res[i-1]&&right>res[i-1])
					res[i]=*++iter;
				else
					res[i]=*--iter;
			}
		}
		else
		{
			multiset<int>::iterator iter1=iter;
			--iter;
			res[0]=*iter/2.0+*iter1/2.0;
			for(int i=1;i<(int)res.size();i++)
			{
				int left=nums[i-1];
				int right=nums[i+k-1];
				if(left!=*iter&&left!=*iter1)
					s.erase(s.find(left));
				else
				{
					if(left==*iter)
						s.erase(iter);
					else
						s.erase(iter1);
					
					s.insert(right);
					iter=s.begin();
					advance(iter,k/2);
					iter1=iter;
					--iter;
					res[i]=*iter/2.0+*iter1/2.0;
					continue;
				}
				s.insert(right);
				if((left<=*iter&&right<=*iter)||(left>=*iter1&&right>=*iter1))
					res[i]=*iter/2.0+*iter1/2.0;
				else if(left<*iter)
				{
					if(right>=*iter1)
						res[i]=*(++iter)/2.0+*(++iter1)/2.0;
					else
						res[i]=*(++iter)/2.0+*(iter1)/2.0;
				}
				else if(left>*iter1)
				{
					if(right<*iter)
						res[i]=*(--iter)/2.0+*(--iter1)/2.0;
					else
						res[i]=*(iter)/2.0+*(--iter1)/2.0;
				}
			}
		}
		
		return res;
    }
};