#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
		int i=0,j=0,len=paragraph.length();
		unordered_map<string,int> dict;
		for(int i=0;i<len;i++)
		{
			if(paragraph[i]>='A'&&paragraph[i]<='Z')
				paragraph[i]=paragraph[i]-'A'+'a';
			if(paragraph[i]<'a'||paragraph[i]>'z')
				paragraph[i]=' ';
		}
		while(i<len)
		{
			while(j<len&&paragraph[j]!=' ')
				j++;
			dict[paragraph.substr(i,j-i)]++;
			while(j<len&&paragraph[j]==' ')
				j++;
			i=j;
		}
		for(int i=0;i<(int)banned.size();i++)
			dict.erase(banned[i]);
		int freq=0;
		string res;
		for(auto n : dict)
		{
			if(n.second>freq)
            {
				res=n.first;
                freq=n.second;
            }
		}
		return res;
    }
};