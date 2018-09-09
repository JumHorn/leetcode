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

// two great way
// class Solution {
// public:
//     vector<int> diffWaysToCompute(string input) {
//         vector<int> result;
//         int size = input.size();
//         for (int i = 0; i < size; i++) {
//             char cur = input[i];
//             if (cur == '+' || cur == '-' || cur == '*') {
//                 // Split input string into two parts and solve them recursively
//                 vector<int> result1 = diffWaysToCompute(input.substr(0, i));
//                 vector<int> result2 = diffWaysToCompute(input.substr(i+1));
//                 for (auto n1 : result1) {
//                     for (auto n2 : result2) {
//                         if (cur == '+')
//                             result.push_back(n1 + n2);
//                         else if (cur == '-')
//                             result.push_back(n1 - n2);
//                         else
//                             result.push_back(n1 * n2);    
//                     }
//                 }
//             }
//         }
//         // if the input string contains only number
//         if (result.empty())
//             result.push_back(atoi(input.c_str()));
//         return result;
//     }
// };

// with DP to optimize
// class Solution {
// public:
// 	vector<int> diffWaysToCompute(string input) {
// 		unordered_map<string, vector<int>> dpMap;
// 		return computeWithDP(input, dpMap);
// 	}

// 	vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
// 		vector<int> result;
// 		int size = input.size();
// 		for (int i = 0; i < size; i++) {
// 			char cur = input[i];
// 			if (cur == '+' || cur == '-' || cur == '*') {
// 				// Split input string into two parts and solve them recursively
// 				vector<int> result1, result2;
// 				string substr = input.substr(0, i);
// 				// check if dpMap has the result for substr
// 				if (dpMap.find(substr) != dpMap.end())
// 					result1 = dpMap[substr];
// 				else
// 					result1 = computeWithDP(substr, dpMap);

// 				substr = input.substr(i + 1);
// 				if (dpMap.find(substr) != dpMap.end())
// 					result2 = dpMap[substr];
// 				else
// 					result2 = computeWithDP(substr, dpMap);
				
// 				for (auto n1 : result1) {
// 					for (auto n2 : result2) {
// 						if (cur == '+')
// 							result.push_back(n1 + n2);
// 						else if (cur == '-')
// 							result.push_back(n1 - n2);
// 						else
// 							result.push_back(n1 * n2);
// 					}
// 				}
// 			}
// 		}
// 		// if the input string contains only number
// 		if (result.empty())
// 			result.push_back(atoi(input.c_str()));
// 		// save to dpMap
// 		dpMap[input] = result;
// 		return result;
// 	}
// };