#include<vector>
#include<string>
#include<unordered_map>
using namespace std;


class WordFilter {
	struct TreeNode
	{
		TreeNode *node[26];
		int weight;
		TreeNode(int w=-1):node({NULL}),weight(-1){}
	};

	TreeNode* prefixroot;
	TreeNode* suffixroot;
	vector<string>& m_words;

	void prefixInsert(const string& word,int weight)
	{
		TreeNode* tmp=prefixroot;
		for(int i=0;i<(int)word.length();i++)
		{
			if(tmp->node[word[i]-'a']==NULL)
				tmp->node[word[i]-'a']=new TreeNode();
			tmp=tmp->node[word[i]-'a'];
		}
		tmp->weight=weight;
	}

	void suffixInsert(const string& word,int weight)
	{
		TreeNode* tmp=suffixroot;
		for(int i=word.length()-1;i>=0;i--)
		{
			if(tmp->node[word[i]-'a']==NULL)
				tmp->node[word[i]-'a']=new TreeNode();
			tmp=tmp->node[word[i]-'a'];
		}
		tmp->weight=weight;
	}

	TreeNode* prefixSearch(const string& word)
	{
		TreeNode* tmp=prefixroot;
		for(int i=0;i<(int)word.length();i++)
		{
			if(tmp->node[word[i]-'a']==NULL)
				return NULL;
			tmp=tmp->node[word[i]-'a'];
		}
		return tmp;
	}

	TreeNode* suffixSearch(const string& word)
	{
		TreeNode* tmp=suffixroot;
		for(int i=word.length()-1;i>=0;i--)
		{
			if(tmp->node[word[i]-'a']==NULL)
				return NULL;
			tmp=tmp->node[word[i]-'a'];
		}
		return tmp;
	}

	void dfs(TreeNode* root,unordered_map<int,int>& m)
	{
		if(root==NULL)
			return;
		if(root->weight>=0)
			++m[root->weight];
		for(int i=0;i<26;i++)
			dfs(root->node[i],m);
	}

public:
    WordFilter(vector<string>& words):m_words(words) {
        prefixroot=new TreeNode();
        suffixroot=new TreeNode();
		for(int i=0;i<(int)words.size();i++)
		{
			prefixInsert(words[i],i);
			suffixInsert(words[i],i);
		}
    }
    
    int f(string prefix, string suffix) {
        unordered_map<int,int> m;
		TreeNode *pfx=prefixSearch(prefix),*sfx=suffixSearch(suffix);
		if(pfx==NULL||sfx==NULL)
			return -1;
		dfs(pfx,m);
		dfs(sfx,m);
		int res=-1;
		for(auto& n : m)
			if(n.second>=2&&n.first>res)
				res=n.first;
		return res;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
