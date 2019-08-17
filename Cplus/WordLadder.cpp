#include<string>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> words(wordList.begin(),wordList.end());
	    queue<string> q;
		q.push(beginWord);	
		if(words.find(endWord)==words.end())
			return 0;
		int res=1;
		while(!q.empty())
		{
			int size=q.size();
			++res;
			while(--size>=0)
			{
				string tmp=q.front();
				q.pop();
				for(int i=0;i<(int)tmp.length();i++)
				{
					char origin=tmp[i];
					for(char c='a';c<='z';c++)
					{
						tmp[i]=c;
						if(words.find(tmp)!=words.end())
						{
							if(tmp==endWord)
								return res;
							q.push(tmp);
							words.erase(tmp);
						}
					}
					tmp[i]=origin;
				}
			}
		}
		return 0;
    }
};
