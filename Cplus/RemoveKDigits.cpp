#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
		if(k>=(int)num.size())
			return "0";
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
					while()
				}
			}
			monoqueue.push(num[i++]);
		}
		while(--k>=0)
			monoqueue.pop();
		int len=num.size()-k;
		string res(len,' ');
		while(--len>=0)
		{
			res[len]=monoqueue.top();
			monoqueue.pop();
		}
		return res;
    }
};
