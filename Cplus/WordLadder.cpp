#include<string>
#include<unordered_set>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> words(wordList.begin(),wordList.end());
		unordered_set<string> *beginset=new unordered_set<string>();
		unordered_set<string> *endset=new unordered_set<string>();
		if(words.find(endWord)==words.end())
			return 0;
		beginset->insert(beginWord);
		endset->insert(endWord);
		int res=1;
		while(!beginset->empty())
		{
			if(beginset->size()>endset->size())
				swap(beginset,endset);
			++res;
			unordered_set<string> *newset=new unordered_set<string>();
			for(unordered_set<string>::iterator iter=beginset->begin();iter!=beginset->end();++iter)
			{
				string tmp=*iter;
				for(int i=0;i<(int)tmp.length();i++)
				{
                    char origin=tmp[i];
					for(char c='a';c<='z';c++)
					{
						tmp[i]=c;
                        if(endset->find(tmp)!=endset->end())
							return res;
						if(words.find(tmp)!=words.end())
						{
							words.erase(tmp);
							newset->insert(tmp);
						}
					}
                    tmp[i]=origin;
				}
			}
			beginset=newset;
		}
		return 0;
    }
};