#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		if(s.empty())
			return res;
		if(s[0]=='0')
		{
			restoreIpAddresses(res,s,1,"0",2);
			return res;
		}
		for(int i=0;i<(int)s.length();i++)
		{
			string tmp=s.substr(0,i+1);
			if(stoi(tmp)>255)
				break;
			restoreIpAddresses(res,s,i+1,tmp,2);
		}
		return res;
    }

	void restoreIpAddresses(vector<string>& res,const string& s,int index,string ip,int num)
	{
		if(index>=(int)s.length())
			return;
		if(num<=0)
		{
			string tmp=s.substr(index);
			if(tmp.size()>0&&tmp.size()<4)
			{
				int val=stoi(tmp);
				if(tmp[0]=='0')
				{
					if(tmp.length()==1)
						res.push_back(ip+"."+tmp);
				}
				else if(val<=255)
					res.push_back(ip+"."+tmp);
			}
			return;
		}
		for(int i=index;i<(int)s.length();i++)
		{
			string tmp=s.substr(index,i-index+1);
			if(s[index]=='0')
			{
				restoreIpAddresses(res,s,i+1,ip+".0",num-1);
				break;
			}
			if(stoi(tmp)>255)
				break;
			restoreIpAddresses(res,s,i+1,ip+"."+tmp,num-1);
		}
	}
};
