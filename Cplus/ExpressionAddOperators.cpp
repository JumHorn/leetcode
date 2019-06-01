#include<vector>
#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<string> addOperators(string num, int target) {
		vector<string> res;
		for(int i=0;i<(int)num.size();i++)
			addOperators(num,i+1,stoi(num.substr(0,i+1)),target,num.substr(0,i+1),res);
		return res;
    }

	void addOperators(const string& num,int i,int val,int target,string str,vector<string>& res)
	{
		if(i>=(int)num.size())
		{
			if(target==val)
				res.push_back(str);
			return;
		}

		for(int j=i+1;j<=(int)num.size();j++)
		{
			string tmp=num.substr(i,j-i);
			int k=stoi(tmp);

			string str1=str;
			int val1=val;
			str1+='+';
			val1+=k;
			str1+=tmp;
			addOperators(num,j,val1,target,str1,res);

			str1=str;
			val1=val;
			str1+='-';
			val1-=k;
			str1+=tmp;
			addOperators(num,j,val1,target,str1,res);

			str1=str;
			val1=val;
			str1+='*';
			val1*=k;
			str1+=tmp;
			addOperators(num,j,val1,target,str1,res);

            if(num[i]=='0')
                break;
		}
	}
};

int main()
{
	Solution sol;
	auto v=sol.addOperators(string("600"),6);
	for(auto n:v)
		cout<<n<<endl;
}