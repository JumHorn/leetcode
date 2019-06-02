#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class MedianFinder {
	vector<int> v;
	map<int,int> small;
	map<int,int> large;
	pair<int,int> lhs;
	pair<int,int> rhs;
	bool even;
public:
    /** initialize your data structure here. */
    MedianFinder() :v(101){
		even=true;
    }
    
    void addNum(int num) {
        if(num<0)
			++small[num];
		else if(num>100)
			++large[num];
		else
			v[num]++;
		
		if(even)
		{
			even=!even;
			if(lhs.second==0&&rhs.second==0)
			{
				lhs.first=rhs.first=num;
				lhs.second=rhs.second=1;
			}
			else if(num<=lhs.first)
			{
				if(num<lhs.first)
					rhs=lhs;
				else
				{
					lhs.second++;
					rhs=lhs;
				}
				
			}
			else if(num>=rhs.first)
			{
				lhs=rhs;
			}
			else
			{
				lhs.first=num;
				lhs.second=1;
				rhs=lhs;
			}
		}
		else
		{
			even=!even;
			if(num<lhs.first)
			{
				map<int,int>::iterator iter=large.find(lhs.first);
				if(iter!=large.end())
				{
					if(lhs.second>1)
					{
						lhs.second--;
						return;
					}
					else
					{
						if(iter!=large.begin())
						{
							--iter;
							lhs.first=iter->first;
							lhs.second=iter->second;
							return;
						}
					}
				}
				for(int i=min(100,lhs.first);i>=0;i--)
				{
					if(v[i]!=0)
					{
						if(i==lhs.first)
						{
							if(lhs.second>1)
							{
								lhs.second--;
								return;
							}
						}
						else
						{
							lhs.first=i;
							lhs.second=v[i];
							return;
						}
					}
				}
				iter=small.find(lhs.first);
				if(iter!=small.end())
				{
					if(lhs.second>1)
					{
						lhs.second--;
						return;
					}
					else
					{
						if(iter!=small.begin())
						{
							--iter;
							lhs.first=iter->first;
							lhs.second=iter->second;
							return;
						}
					}
				}
				else
				{
					iter=small.end();
					--iter;
					lhs.first=iter->first;
					lhs.second=iter->second;
				}
				
			}
			else if(num>=rhs.first)
			{
				map<int,int>::iterator iter=small.find(rhs.first);
				if(iter!=small.end())
				{
					if(rhs.second<iter->second)
					{
						rhs.second++;
						return;
					}
					else
					{
						++iter;
						if(iter!=small.end())
						{
							rhs.first=iter->first;
							rhs.second=1;
							return;
						}
					}
				}
				for(int i=max(0,rhs.first);i<=100;i++)
				{
					if(v[i]!=0)
					{
						if(rhs.first==i)
						{
							if(rhs.second<v[i])
							{
								rhs.second++;
								return;
							}
						}
						else
						{
							rhs.first=i;
							rhs.second=1;
							return;
						}
					}
				}
				iter=large.find(rhs.first);
				if(iter!=large.end())
				{
					if(rhs.second<iter->second)
					{
						rhs.second++;
						return;
					}
					else
					{
						++iter;
						if(iter!=large.end())
						{
							rhs.first=iter->first;
							rhs.second=1;
							return;
						}
					}
				}
				else
				{
					iter=large.begin();
					rhs.first=iter->first;
					rhs.second=1;
				}	
			}
		}
    }
    
    double findMedian() {
        return (lhs.first+rhs.first)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */