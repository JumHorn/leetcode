#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
		sortdict(dict);
		int i=0,j,k;
		while(i<sentence.length()&&sentence[i]==' ')i++;
		while(i<sentence.length())
		{
			k=i;
			while(k<sentence.length()&&sentence[k]!=' ')k++;
			int l = k-i;
			for(j=0;j<dict.size()&&dict[j].length()<=l;j++)
			{
				int n;
				for(n=0;n<dict[j].length();n++)
				{
					if(dict[j][n]!=sentence[i+n])
					{
						break;
					}
				}
				if(n==dict[j].length())
				{
					sentence.erase(i+dict[j].length(),l-dict[j].length());
                    k=i+dict[j].length();
					break;
				}
			}
		    i=k+1;
		}
		return sentence;
    }

	void sortdict(vector<string>& dict)
	{
		int len = dict.size();
		bool sorted = false;
		while(len>1)
		{
			sorted=true;
			for(int i=0;i<len-1;i++)
			{
				if(dict[i].length()>dict[i+1].length())
				{
					swap(dict[i],dict[i+1]);
					sorted=false;
				}
			}
			if(sorted)
			{
				break;
			}
			len--;
		}
	}
};