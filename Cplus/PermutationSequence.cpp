#include<string>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
		string res(n,'1');
		string candidate=string("123456789").substr(0,n);
		int all=factorial(n-1),index=-1;
        --k;
		for(int i=0;i<n-1;i++)
		{
			int tmp=k/all;
			index=-1;
			k%=all;
			all/=n-i-1;
			for(int j=0;j<=tmp;j++)
				while(candidate[++index]=='0');
            res[i]=candidate[index];
            candidate[index]='0';
		}
		index=-1;
		while(candidate[++index]=='0');
		res[n-1]=candidate[index];
		return res;
    }

	int factorial(int n)
	{
		if(n<2)
			return n;
		return factorial(n-1)*n;
	}
};