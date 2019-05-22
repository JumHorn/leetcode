#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
		map<string,unordered_set<string> > graph;
		for(int i=0;i<(int)wordList.size();i++)
			if(transform(beginWord,wordList[i])==1)
				graph[beginWord].insert(wordList[i]);

		for(int i=0;i<(int)wordList.size()-1;i++)
			for(int j=i+1;j<(int)wordList.size();j++)
				if(transform(wordList[i],wordList[j])==1)
				{
					graph[wordList[i]].insert(wordList[j]);
					graph[wordList[j]].insert(wordList[i]);
				}
        if(graph.find(endWord)==graph.end())
            return vector<vector<string> >();
		map<int,vector<vector<string> > > res;
		vector<string> tmp(1,beginWord);
		unordered_set<string> visited;
		findLadders(graph,res,tmp,visited,endWord);
		return res.begin()->second;
    }

	void findLadders(map<string,unordered_set<string> >& graph,map<int,vector<vector<string> > >& res,vector<string>& tmp,unordered_set<string>& visited,const string& dst)
	{
		if(tmp.back()==dst)
		{
			res[tmp.size()].push_back(tmp);
			return;
		}
		if(visited.find(tmp.back())!=visited.end())
			return;
        //if(graph[tmp.back()].find(dst)!=graph[tmp.back()].end())
        //{
        //    res[tmp.size()+1].push_back(tmp);
        //    res[tmp.size()+1].back().push_back(dst);
        //    return;
        //}
        visited.insert(tmp.back());
		for(unordered_set<string>::iterator iter=graph[tmp.back()].begin();iter!=graph[tmp.back()].end();++iter)
		{
			if(visited.find(*iter)==visited.end())
			{
				tmp.push_back(*iter);
				findLadders(graph,res,tmp,visited,dst);
				tmp.pop_back();
			}
		}
        unordered_set<string>::iterator it=visited.find(tmp.back());
        if(it!=visited.end())
            visited.erase(it);
	}

	int transform(const string& w1,const string& w2)
	{
		int res=0;
		for(int i=0;i<(int)w1.size();i++)
			if(w1[i]!=w2[i])
				res++;
		return res;
	}
};
