#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
		string parenthesis(n*2,' ');
		vector<string> res;
		generateParenthesis(res,parenthesis,0,0,0);
		return res;
    }

	void generateParenthesis(vector<string>& res,string& parenthesis,int start,int left,int right)
	{
		if(start==(int)parenthesis.size())
		{
			res.push_back(parenthesis);
			return;
		}
		if(left==right)
		{
			parenthesis[start]='(';
			generateParenthesis(res,parenthesis,start+1,left+1,right);
		}
		else if(left>right)
		{
			if(left<(int)parenthesis.size()/2)
			{
				parenthesis[start]='(';
				generateParenthesis(res,parenthesis,start+1,left+1,right);
			}
			parenthesis[start]=')';
			generateParenthesis(res,parenthesis,start+1,left,right+1);
		}
	}
};
