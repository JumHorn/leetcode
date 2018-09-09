#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
		Compute(res,input);
	    return res;
    }

	void Compute(vector<int>& res,string input)
	{
		int front=0,middle=0,back=1;
		while(back!=input.length())
		{
			if(input[back]=='+'||input[back]=='-'||input[back]=='*')
			{
				middle=back;
				break;
			}
			back++;
		}
		back++;
		if(back!=input.length()&&input[back]=='-')
		{
			back++;
		}
		while(back!=input.length())
		{
			if(input[back]=='+'||input[back]=='-'||input[back]=='*')
			{
				Calculate(res,input,input[middle],front,middle,back);
			}
			else
			{
				back++;
			}
		}
		res.push_back(stoi(deleteSymbol(add(input,input[middle],front,middle,back))));
	}

	void Calculate(vector<int>& res,string& input,char symbol,int& front,int& middle,int& back)
	{
		Compute(res,add(input,symbol,front,middle,back));
		front=middle+1;
		middle=back;
		back++;
		if(back!=input.length()&&input[back]=='-')
		{
			back++;
		}
	}

	string add(string input,char symbol,int front,int middle,int back)
	{
		int a=stoi(input.substr(front,middle-front));
		int b=stoi(input.substr(middle+1,back-middle-1));
		int c;
		switch(symbol)
		{
		case '+':
			c=a+b;
			break;
		case '-':
			c=a-b;
			break;
		case '*':
			c=a*b;
			break;
		}
		string tmp=input.replace(front,back-front,to_string(c));
		return tmp;
	}

	string deleteSymbol(string input)
	{
		for(int i=1;i<input.length();i++)
		{
			if(input[i]=='+'||input[i]=='-'||input[i]=='*')
			{
				return add(input,input[i],0,i,input.length());
			}
		}
		return input;
	}
};
