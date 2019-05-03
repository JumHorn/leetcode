#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        for(int i=0;i<(int)S.length()-1;i++)
		{
			int a, b;
			if(S[0]=='0'&&i!=0)
				break;
			a=stoi(S.substr(0,i+1));
			for(int j=i+1;j<(int)S.length();j++)
			{
				if(S[i+1]=='0'||j==(int)S.length()-1)
					break;
				b=stoi(S.substr(i+1,j-i));
				if(a>b)
					continue;
				vector<int> res;
				res.push_back(a);
				res.push_back(b);
				if(splitIntoFibonacci(res,S,a,b,j+1))
					return res;
			}
		}
		return vector<int>();
    }

	bool splitIntoFibonacci(vector<int>& res,const string& s,int a,int b,int start)
	{
		if(start==(int)s.length())
			return true;
		if(s[start]=='0')
			return false;
		int c=a+b;
		for(int i=start;i<(int)s.length();i++)
		{
			int tmp=stoi(s.substr(start,i-start+1));
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
