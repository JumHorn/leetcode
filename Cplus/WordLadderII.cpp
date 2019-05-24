#include<vector>
#include<string>
#include<set>
#include<unordered_set>
#include<map>
#include<queue>
using namespace std;

class Solution {
public:
	vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
		map<string,unordered_set<string> > graph;
		vector<vector<string> >  res;
		unordered_set<string> visited;
		unordered_set<string> words(wordList.begin(),wordList.end());
		queue<string> q;
		int depth=1;
		q.push(beginWord);
		bool flag=true;
		while(!q.empty()&&flag)
		{
			int n=q.size();
			depth+=1;
			for(unordered_set<string>::iterator iter=visited.begin();iter!=visited.end();++iter)
				words.erase(*iter);
			visited.clear();
			while(--n>=0)
			{
				string t=q.front();
				for(int i=0;i<(int)t.length();i++)
				{
					for(char c='a';c<='z';c++)
					{
						t[i]=c;
						if(words.find(t)!=words.end())
						{
							graph[q.front()].insert(t);
							q.push(t);
							visited.insert(t);
							if(t==endWord)
								flag=false;
						}	
					}
					t=q.front();
				}
				q.pop();
			}
		}
		if(flag)
			return vector<vector<string> >();

		//BFS
		visited.clear();
		vector<string> tmp(depth);
		tmp[0]=beginWord;
		tmp[depth-1]=endWord;
		findLadders(graph,res,tmp,visited,endWord,depth);
		return res;
	}
	//DFS
	void findLadders(map<string,unordered_set<string> >& graph,vector<vector<string> >& res,vector<string>& tmp,unordered_set<string>& visited,const string& dst,int depth)
	{
		if(depth<=2)
		{
			if(graph[tmp[tmp.size()-depth]].find(dst)!=graph[tmp[tmp.size()-depth]].end())
				res.push_back(tmp);
			return;
		}
		for(unordered_set<string>::iterator iter=graph[tmp[tmp.size()-depth]].begin();iter!=graph[tmp[tmp.size()-depth]].end();++iter)
		{
			if(visited.find(*iter)==visited.end())
			{
				visited.insert(*iter);
				tmp[tmp.size()-depth+1]=*iter;
				findLadders(graph,res,tmp,visited,dst,depth-1);
				visited.erase(visited.find(*iter));
			}
		}
	}
};
