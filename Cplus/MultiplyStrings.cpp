#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
		int N1=num1.size(),N2=num2.size();
		if(num2=="0")
			return "0";
		string res(N1+N2,'0');
		int index=0;
		for(int i=0;i<(int)num1.length();i++)
		{
			if(num1[i]!='0')
				index=max(index,multiply(res,num2,num1.length()-i-1,num1[i]-'0'));
		}
		if(index<=0)
			return "0";
		res=res.substr(0,index);
		reverse(res.begin(),res.end());
		return res;
    }

	int multiply(string& res,const string& num,int index,int n)
	{
		int bit=0;
		for(int i=num.length()-1;i>=0;i--)
		{
			int tmp=(num[i]-'0')*n+bit+(res[index]-'0');
			res[index++]=tmp%10+'0';
			bit=tmp/10;
		}
		while(bit>0)
		{
			bit+=res[index]-'0';
			res[index++]=bit%10+'0';
			bit/=10;
		}
		return index;
	}
};
