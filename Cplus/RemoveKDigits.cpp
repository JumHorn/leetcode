#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
		if(k>=(int)num.size())
			return "0";
		int len=num.size()-k;
		string res(len,' ');
		stack<char> monoqueue;
		int i=0;
		monoqueue.push(num[i++]);
		while(i<(int)num.size())
		{
			while(!monoqueue.empty()&&monoqueue.top()>num[i])
			{
				monoqueue.pop();
				k--;
				if(k==0)
				{
					int s=monoqueue.size();
					int t=s;
					while(--s>=0)
					{
						res[s]=monoqueue.top();
						monoqueue.pop();
					}
					while(i<(int)num.size())
						res[t++]=num[i++];
                    i=0;
                    while(i<(int)res.size()-1&&res[i]=='0')
                        ++i;
					return res.substr(i);
				}
			}
			monoqueue.push(num[i++]);
		}
		while(--k>=0)
			monoqueue.pop();
		while(--len>=0)
		{
			res[len]=monoqueue.top();
			monoqueue.pop();
		}
        i=0;
        while(i<(int)res.size()-1&&res[i]=='0')
            ++i;
		return res.substr(i);
    }
};