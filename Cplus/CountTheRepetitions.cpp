#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
		if(n1==0)
			return 0;
		int N=s1.length(),M=s2.length(),count=0,index=0;
		vector<int> countarray(M+1),indexarray(M+1);
		for(int i=0;i<n1;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(s1[j]==s2[index])
					++index;
				if(index==M)
				{
					index=0;
					++count;
				}
			}
			countarray[i]=count;
			indexarray[i]=index;
			for(int k=0;k<i;k++)
			{
				if(index==indexarray[k])
				{
					int pre=countarray[k];
					int pattern=(countarray[i]-countarray[k])*((n1-k-1)/(i-k));
					int remain=countarray[k+(n1-k-1)%(i-k)]-countarray[k];
					return (pre+pattern+remain)/n2;
				}
			}
		}
		return countarray[n1-1]/n2;
    }
};
