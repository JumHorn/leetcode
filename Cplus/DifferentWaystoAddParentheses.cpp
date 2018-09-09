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
			if(input[back]=='+')
			{
				int a=stoi(input.substr(front,middle-front));
				int b=stoi(input.substr(middle+1,back-middle-1));
				int c=a+b;
				string tmp=input.replace(front,back-front,to_string(c));
				Compute(res,tmp);
				front=middle+1;
				middle=back;
				back++;
				if(back!=input.length()&&input[back]=='-')
				{
					back++;
				}
			}
			else if(input[back]=='-')
			{
				int a=stoi(input.substr(front,middle-front));
				int b=stoi(input.substr(middle+1,back-middle-1));
				int c=a-b;
				string tmp=input.replace(front,back-front,to_string(c));
				Compute(res,tmp);
				front=middle+1;
				middle=back;
				back++;
				if(back!=input.length()&&input[back]=='-')
				{
					back++;
				}
			}
			else if(input[back]=='*')
			{
				int a=stoi(input.substr(front,middle-front));
				int b=stoi(input.substr(middle+1,back-middle-1));
				int c=a*b;
				string tmp=input.replace(front,back-front,to_string(c));
				Compute(res,tmp);
				front=middle+1;
				middle=back;
				back++;
				if(back!=input.length()&&input[back]=='-')
				{
					back++;
				}
			}
			else
			{
				back++;
			}
		}
		res.push_back(stoi(input));
	}
};
