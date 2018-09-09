#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
		vector<int> res;
		vector<int> numbers;
		vector<char> symbols;
		for(int i=1;i<input.length();i++)
		{
			if(input[i]=='+'||input[i]=='-'||input[i]=='*')
			{
				symbols.push_back(input[i]);
				numbers.push_back(stoi(input.substr(0,i)));
				input=input.substr(i+1);
				i=0;
			}
			else
			{
				i++;
			}
		}
		numbers.push_back(stoi(input));
		Compute(res,numbers,symbols);
	    return res;
	}
	
	void Compute(vector<int>& res,vector<int>& numbers,vector<char>& symbols)
	{
		if(symbols.empty())
		{
			res.push_back(numbers.back());
			return;
		}
		int i=0;
		while(i!=symbols.size())
		{
			int c;
			switch(symbols[i])
			{
			case '+':
				c=numbers[i]+numbers[i+1];
			break;
			case '-':
				c=numbers[i]-numbers[i+1];
			break;
			case '*':
				c=numbers[i]*numbers[i+1];
			break;
			}
			vector<int> num=numbers;
			vector<char> sym=symbols;
			num[i++]=c;
			num.erase(num.begin()+i);
			sym.erase(sym.begin()+i-1);
			Compute(res,num,sym);
		}
	}
};

// template<typename T>
// ostream& operator<<(ostream& os,T& t)
// {
// 	for(typename T::iterator iter=t.begin();iter!=t.end();iter++)
// 	{
// 		os<<*iter<<" ";
// 	}
// 	os<<endl;
// 	return os;
// }
