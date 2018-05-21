#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
		vector<int> result;
        int head = 0,tail = S.length()-1,i,j;
		while(head != tail+1)
		{
			i = head;
			for(j = tail;j>=i;j--)
			{
				if(S[j]==S[i])
				{
					break;
				}
			}
			for(int l=i+1;l<j;l++)
			{
				for(int k = tail;k>j;k--)
				{
					if(S[k]==S[l])
					{
						j = k;
					}
				}
			}
			result.push_back(j-head+1);
			head = j+1;
		}	
		return result;
    }
};
