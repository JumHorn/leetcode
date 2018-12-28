#include<string>
#include<map>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.size()<2)
            return dominoes;
		map<int,char> m;
		for(int i=0;i<dominoes.length();i++)
			if(dominoes[i]!='.')
				m[i]=dominoes[i];
        if(m.empty())
            return dominoes;
		map<int,char>::iterator it1=m.begin(),it2;
		it2=it1;
		for(++it2;it2!=m.end();++it1,++it2)
		{
			if(it1->second=='R'&&it2->second=='L')
			{
				int i=it1->first+1;
				int j=it2->first-1;
				while(i<j)
				{
					dominoes[i++]='R';
					dominoes[j--]='L';
				}
			}
			else if(it1->second==it2->second)
				for(int i=it1->first+1;i<it2->first;i++)
					dominoes[i]=it1->second;
		}
		it1=m.begin();
		it2=--m.end();
		if(it1->second=='L')
			for(int i=0;i<it1->first;i++)
				dominoes[i]='L';
		if(it2->second=='R')
			for(int i=it2->first+1;i<dominoes.size();i++)
				dominoes[i]='R';
		return dominoes;
    }
};
