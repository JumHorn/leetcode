#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
		int targetchar=0;
        map<char,int> t;
		vector<map<char,int> > s(stickers.size());
		for(int i=0;i<(int)target.size();i++)
		{
			targetchar++;
			++t[target[i]];
		}
		for(int i=0;i<(int)stickers.size();i++)
			for(int j=0;j<(int)stickers[i].size();j++)
				++s[i][stickers[i][j]];
		int res=0,tmpchar,minchar=INT_MAX;
		map<char,int> tmpmap,minmap;
		while(true)
		{
			for(int i=0;i<(int)s.size();i++)
			{
				tmpchar=targetchar;
				for(map<char,int>::iterator iter=t.begin();iter!=t.end();++iter)
				{
					if(iter->second>=s[i][iter->first])
					{
						tmpmap[iter->first]=iter->second-s[i][iter->first];
						tmpchar-=s[i][iter->first];
					}
					else
					{
						tmpmap[iter->first]=0;
						tmpchar-=iter->second;
					}
				}
				if(tmpchar<minchar)
				{
					minchar=tmpchar;
					minmap=tmpmap;
				}
			}
			if(targetchar==0)
				break;
			if(targetchar==minchar)
				return -1;
			t=minmap;
			targetchar=minchar;
			res++;
		}
		return res;
    }
};

int main()
{
	vector<string> v;
	v.push_back("with");
	v.push_back("example");
	v.push_back("science");
	Solution sol;
	sol.minStickers(v,"thehat");
	return 0;
}