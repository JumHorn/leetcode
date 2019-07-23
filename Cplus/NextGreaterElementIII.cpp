#include<string>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
		string s(to_string(n));
		int i=s.size();
		while(--i>0)
		{
			if(s[i]>s[i-1])
			{
				int j=s.size();
				while(--j>=i)
				{
					if(s[j]>s[i-1])
					{
						swap(s[j],s[i-1]);
						reverse(s.begin()+i,s.end());
						long res=stol(s);
						return res>INT_MAX?-1:res;
					}
				}
			}
		}
		return -1;
    }
};
