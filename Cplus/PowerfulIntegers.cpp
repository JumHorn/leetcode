#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
		vector<int> res;
		if(x>y)
			swap(x,y);
		int a=1,b=1;
        if(y==1)
        {
            if(bound>=2)
                res.push_back(2);
            return res;
        }
        if(x==1)
        {
            while(b<=bound)    
            {
                res.push_back(b+1);
                b*=y;
            }
            return res;
        }
		res.push_back(a+b);
		while(true)
		{
			if(a>b)
			{
				int c=1;
				int tmp=b*y;
				while(true)
				{
					if(a+c>tmp||a+c>bound)
						break;
					if(a+c>res.back())
						res.push_back(a+c);
                    else if(a+c<res.back()&&a+c>res[res.size()-2])
                        res.push_back(a+c);
					c*=y;
				}
                if(a<tmp)
                {
                    a*=x;
                    continue;
                }
                else
                {
                    a=1;
                    b*=y;
                }
			}
			if(a+b>bound)
				break;
			if(a+b!=res.back())
				res.push_back(a+b);
			a*=x;
		}
		return res;
    }
};