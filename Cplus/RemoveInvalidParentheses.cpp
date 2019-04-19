#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> removeInvalidParentheses(string s) {
		vector<string> res;
		int open=0,close=0,count=0;//open ( for remove close ) for remove
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]=='(')
				++count;
			else if(s[i]==')')
				--count;
			if(count<0)
			{
				close++;
				count=0;
			}
		}	
		open=count;	
		if(open==0&&close==0)
		{
			res.push_back(s);
			return res;
		}
		if(open+close==(int)s.length())
		{
			res.push_back("");
			return res;
		}
		unordered_set<string> result;
		removeInvalidParentheses(result,s,open,close,0);
		for(unordered_set<string>::iterator iter=result.begin();iter!=result.end();++iter)
			res.push_back(*iter);
		return res;
	}

	bool isValid(const string& s)
	{
		int count=0;
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]=='(')
				++count;
			else if(s[i]==')')
				--count;
			if(count<0||count>(int)s.length()/2)
				return false;
		}
		return count==0;
	}

	void removeInvalidParentheses(unordered_set<string>& res,string s,int open,int close,int start)
	{
		if(open==0&&close==0)
		{
			if(isValid(s))
				res.insert(s);
			return;
		}
		for(int i=start;i<(int)s.length();i++)
		{
			if(s[i]=='(')
			{
				if(open>0)
				{
					string tmp=s;
					tmp.erase(tmp.begin()+i);
					removeInvalidParentheses(res,tmp,open-1,close,i);
				}
			}
			else if(s[i]==')')
			{
				if(close>0)
				{
					string tmp=s;
					tmp.erase(tmp.begin()+i);
					removeInvalidParentheses(res,tmp,open,close-1,i);
				}
			}
		}
	}
};

int main()
{
	Solution sol;
	sol.removeInvalidParentheses(")()(");
}
