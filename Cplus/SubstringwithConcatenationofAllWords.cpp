#include<vector>
#include<string>
#include<cstring>
using namespace std;

class Solution {
private:
	struct TreeNode
	{
		//char val;
		int count;
		int reduce;//for reduce and reset;
		TreeNode* node[26]; 
		TreeNode():count(0),reduce(0)
		{
			memset(node,0,sizeof(node));
		}
		~TreeNode()
		{
			for(int i=0;i<26;i++)
		  	if(node[i]!=NULL)
		  		delete node[i];
	  	}
	};

    TreeNode* root;

    	/** Inserts a word into the trie. */
	void insert(const string& word) 
	{
		TreeNode* tmp=root;
		for(int i=0;i<(int)word.length();i++)
		{
			int index=word[i]-'a';
			if(tmp->node[index]==NULL)
			{
				tmp->node[index]=new TreeNode();
			}
			tmp=tmp->node[index];
		}
		tmp->count++;
		tmp->reduce++;
	}

	void resetTrie(TreeNode* root)
	{
		if(root==NULL)
			return;
		root->reduce=root->count;
		for(int i=0;i<26;i++)
			resetTrie(root->node[i]);
	}
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(s.empty()||words.empty())
            return res;
        root=new TreeNode();
		vector<char> charmap(26);
		int windowsize=0;
		for(int i=0;i<(int)words.size();i++)
		{
			for(int j=0;j<(int)words[i].size();j++)
				++charmap[words[i][j]-'a'];
			windowsize+=words[i].size();
		}
		if((int)s.length()<windowsize)
			return res;
		vector<char> windowmap(26);
		for(int i=0;i<windowsize;i++)
			++windowmap[s[i]-'a'];
		buildTree(words);

		if(windowmap==charmap)
		{
			if(compareWindow(root,s,0,windowsize))
				res.push_back(0);
		}
		for(int i=windowsize;i<(int)s.length();i++)
		{
			++windowmap[s[i]-'a'];
			--windowmap[s[i-windowsize]-'a'];
			if(windowmap==charmap)
			{
				resetTrie(root);
				if(compareWindow(root,s,i-windowsize+1,i+1))
					res.push_back(i-windowsize+1);
			}
		}
		return res;
    }

	bool compareWindow(TreeNode* tree,const string& s,int index,int end)
	{
		for(int i=index;i<end;i++)
		{
            tree=tree->node[s[i]-'a'];
            if(tree==NULL)
                return false;
            if(tree->reduce>0)
            {
                --tree->reduce;
                if(compareWindow(root,s,i+1,end))
                    return true;
                ++tree->reduce;
                if(compareWindow(tree,s,i+1,end))
                    return true;
            }
            else
                return compareWindow(tree,s,i+1,end);
        }
		return tree->reduce>0;
	}

	void buildTree(vector<string>& words)
	{
		for(int i=0;i<(int)words.size();i++)
			insert(words[i]);
	}
};