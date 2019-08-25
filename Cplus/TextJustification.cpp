#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
		vector<string> res;
		string tmp(maxWidth,' ');		
		for(int i=0;i<(int)words.size();)
		{
			fill(tmp.begin(),tmp.end(),' ');
			int len=words[i].size();
			int j=i;
			while(++j<(int)words.size()&&(int)(len+words[j].size()+1)<=maxWidth)
				len+=words[j].size()+1;
			if(j==(int)words.size())
			{
				copy(words[i].begin(),words[i].end(),tmp.begin());
				int start=words[i].size();
				for(int k=i+1;k<j;k++)
				{
					start+=1;
					copy(words[k].begin(),words[k].end(),tmp.begin()+start);
					start+=words[k].size();
				}
                res.push_back(tmp);
				break;
			}
			int num=j-i;//the number of words in one line
			if(num==1)
				copy(words[i].begin(),words[i].end(),tmp.begin());
			else
			{
				int space=(maxWidth-len)/(num-1)+1;
				int bigspace=(maxWidth-len)%(num-1);
				copy(words[i].begin(),words[i].end(),tmp.begin());
				int start=words[i].size();
				for(int k=i+1;k<j;k++)
				{
					if(--bigspace>=0)
						start+=space+1;
					else
						start+=space;
					copy(words[k].begin(),words[k].end(),tmp.begin()+start);
					start+=words[k].size();
				}
			}
			res.push_back(tmp);
			i=j;
		}
		return res;
    }
};