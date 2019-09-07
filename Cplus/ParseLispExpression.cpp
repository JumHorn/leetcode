#include<string>
#include<unordered_map>
#include<vector>
#include<cctype>
using namespace std;

class Solution {
public:
    int evaluate(string expression) {
        if(expression.empty())
			return 0;
		vector<unordered_map<string,int>> variables;
		return evaluate(expression,1,expression.length()-1,variables);
    }

	int evaluate(const string& expression,int start,int end,vector<unordered_map<string,int>>& variables)
	{
		int i=start,j=start,res=0;
		unordered_map<string,int> localvar;
		variables.push_back(localvar);
		while(i<end)
		{
			if(expression[i]=='(')
			{
				j=matchParethesis(expression,i);
				res=evaluate(expression,i+1,j,variables);
				break;
			}
			while(j<end&&expression[j]!=' ')
                j++;
			string exp=expression.substr(i,j-i);
			if(exp=="let")
			{
				i=++j;
				while(j<end)
				{
					if(expression[i]=='(')
					{
						j=matchParethesis(expression,i);
						res=evaluate(expression,i+1,j,variables);
						i=++j;
					}
                    else
                    {
                        while(j<end&&expression[j]!=' ')
                            j++;
                        string valname=expression.substr(i,j-i);
                        if(j>=end-1)
                        {
                            res=evaluate(valname,variables);
                            i=++j;
                            break;
                        }
                        i=++j;
                        if(expression[i]=='(')
                        {
                            j=matchParethesis(expression,i);
                            variables.back()[valname]=evaluate(expression,i,j,variables);
                        }
                        else
                        {
                            while(j<end&&expression[j]!=' ')
                                j++;
                            variables.back()[valname]=evaluate(expression.substr(i,j-i),variables);
                        }
                        while(++j<end&&expression[j]==' ');
                        i=j;
                    }
				}
			}
			else
			{
				i=++j;
				int lhs,rhs;
				if(expression[i]=='(')
				{
					j=matchParethesis(expression,i);
					lhs=evaluate(expression,i+1,j,variables);
				}
				else
                {
                    while(j<end&&expression[j]!=' ')
                        j++;
                    lhs=evaluate(expression.substr(i,j-i),variables);
                }
				
                j++;
				while(j<end&&expression[j]==' ')
                    j++;
                i=j;

				if(expression[i]=='(')
				{
					j=matchParethesis(expression,i);
					rhs=evaluate(expression,i+1,j,variables);
				}
				else
                {
                    while(j<end&&expression[j]!=' ')
                        j++;
                    rhs=evaluate(expression.substr(i,j-i),variables);
                }

                if(exp=="add")
                    res=lhs+rhs;
                else if(exp=="mult")
                    res=lhs*rhs;
                i=++j;
			}
		}
        variables.pop_back();
		return res;
	}

    int evaluate(const string& expression,vector<unordered_map<string,int>>& variables)
    {
        int res = 0;
        if(isdigit(expression[0])||expression[0]=='-')
            res=stoi(expression);
        else
        {
            for(int i=variables.size()-1;i>=0;i--)
            {
                if(variables[i].find(expression)!=variables[i].end())
                {
                    res=variables[i][expression];
                    break;
                }
            }
        }
        return res;  
    }

	int matchParethesis(const string& expression,int start)
	{
		int parenthesis=1;
		while(++start)
		{
			if(expression[start]=='(')
				parenthesis++;
			else if(expression[start]==')')
				parenthesis--;
			if(parenthesis==0)
				break;
		}
		return start;
	}
};