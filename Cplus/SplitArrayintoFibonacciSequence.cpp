#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for(int i=0;i<(int)S.length()-1;i++)
		{
			long long a, b;
			if(S[0]=='0'&&i!=0)
				break;
			a=stol(S.substr(0,i+1));
			if(a>=INT_MAX)
				break;
			for(int j=i+1;j<(int)S.length();j++)
			{
				if((S[i+1]=='0'&&j!=i+1)||j==(int)S.length()-1)
					break;
				b=stol(S.substr(i+1,j-i));
				if(b>=INT_MAX)
					break;
				vector<int> res;
				res.push_back(a);
				res.push_back(b);
				if(splitIntoFibonacci(res,S,a,b,j+1))
					return res;
			}
		}
		return vector<int>();
    }

	bool splitIntoFibonacci(vector<int>& res,const string& s,long long a,long long b,int start)
	{
		if(start==(int)s.length())
			return true;
		long long c=a+b;
		if(c>=INT_MAX)
			return false;
		if(c!=0&&s[start]=='0')
			return false;
		for(int i=start;i<(int)s.length();i++)
		{
			long long tmp=stol(s.substr(start,i-start+1));
			if(tmp>c)
				return false;
			if(tmp==c)
			{
				res.push_back(c);
				return splitIntoFibonacci(res,s,b,c,i+1);
			}
		}
		return false;
	}
};
