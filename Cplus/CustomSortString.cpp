#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string customSortString(string S, string T) {
    	char hash[26];
		for(int i=0;i<26;i++)
		{
			hash[i] = 26;
		}

		for(int i=0;i<S.length();i++)
		{
			hash[S[i]-'a'] = i;
		}
		
		for(int i=0;i<T.length()-1;i++)
		{
			if(hash[T[i]-'a'] == 26)
			{
				continue;
			}
			for(int j=i+1;j<T.length();j++)
			{
				if(hash[T[i]-'a']>hash[T[j]-'a'])
				{
					char temp = T[i];
					T[i] = T[j];
					T[j] = temp;
				}
			}
		}	
		return T;
    }
};
