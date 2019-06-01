#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
		vector<string> res;
		for(int i=0;i<(int)num.size();i++)
		{
			string str=num.substr(0,i+1);
			int val=stoi(num.substr(0,i+1));
			addOperators(num,i+1,val,val,target,str,res);
		}
		return res;
    }

	//cv:current value pv:previous value
	void addOperators(const string& num,int i,int cv,int pv,int target,string str,vector<string>& res)
	{
		if(i>=(int)num.size())
		{
			if(target==cv)
				res.push_back(str);
			return;
		}

		for(int j=i+1;j<=(int)num.size();j++)
		{
			string tmp=num.substr(i,j-i);
			int k=stoi(tmp);
			addOperators(num,j,cv+k,k,target,str+'+'+tmp,res);
			addOperators(num,j,cv-k,-k,target,str+'-'+tmp,res);
			addOperators(num,j,cv-pv+k*pv,k*pv,target,str+'*'+tmp,res);

            if(num[i]=='0')
                break;
		}
	}
};