#include<vector>
#include<stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size());
		stack<int> s;
		for(int i=0;i<(int)temperatures.size();i++)
		{
			while(!s.empty())
			{
				if(temperatures[i]<=temperatures[s.top()])
					break;
				result[s.top()]=i-s.top();
				s.pop();
			}
			s.push(i);
		}
        return result;
    }
};
