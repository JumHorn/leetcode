#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
    string frequencySort(string s) {
        map<char,int> hash;
        vector<string> bucket(s.size()+1,"");
        string res;
		for(int i=0;i<s.length();i++)
		{
			hash[s[i]]++;
		}

		for(map<char,int>::iterator iter=hash.begin();iter!=hash.end();iter++)
		{
			bucket[iter->second].append(iter->second,iter->first);
		}

		for(int i=bucket.size()-1;i>=0;i--)
		{
			if(!bucket[i].empty())
			{
				res.append(bucket[i]);
			}
		}

		return res;
    }
};

// time limit exceeded
// class Solution0 {
// public:
//     string frequencySort(string s) {
//         map<char,int> hash;
// 		for(int i=0;i<s.length();i++)
// 		{
// 			if(hash.find(s[i])!=hash.end())
// 			{
// 				hash[s[i]]++;
// 			}
// 			else
// 			{
// 				hash[s[i]]=1;
// 			}
// 		}
//		
// 		bool swap=false;
// 		int len=s.length();
// 		while(true)
// 		{
// 			len--;
// 			swap=false;
// 			for(int i=0;i<len;i++)
// 			{
// 				if(hash[s[i]]<hash[s[i+1]])
// 				{
// 					char temp=s[i];
// 					s[i]=s[i+1];
// 					s[i+1]=temp;
// 					swap=true;
// 				}
// 			}
// 			if(swap==false)
// 			{
// 				break;
// 			}
// 		}
// 		for(int i=0;i<s.length();i++)
// 		{
// 			for(int j=i-1;j>=0;j--)
// 			{
// 				if(hash[s[i]]!=hash[s[j]])
// 				{
// 					break;
// 				}
// 				if(s[i]==s[j])
// 				{
// 					if(i-j>1)
// 					{
// 						s.insert(j,1,s[i]);
// 						s.erase(i+1,1);
// 					}
// 					break;
// 				}
// 			}
// 		}
// 		return s;
//     }
// };
