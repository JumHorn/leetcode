#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
		if(answers.empty())
		{
			return 0;
		}
		sort(answers.begin(),answers.end());        
		int tmp=0;
		unsigned int i;
		for(i=0;i<answers.size();i++)
		{
			if(answers[i]!=0)
			{
				break;
			}
			tmp++;
		}
		int sum=tmp;
		int flag=i;
		tmp=answers[i];
		for(i+=1;i<answers.size();i++)
		{
			if(tmp!=answers[i])
			{
				sum+=((i-flag)/(tmp+1)+((i-flag)%(tmp+1)?1:0))*(tmp+1);
				tmp=answers[i];
				flag=i;
			}
		}
		return sum+((i-flag)/(tmp+1)+((i-flag)%(tmp+1)?1:0))*(tmp+1);
    }
};
