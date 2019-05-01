#include<string>
using namespace std;

class Trie {

	struct TreeNode
	{
		char val;
		int count;
		TreeNode* node[26]; 
		TreeNode(char v):val(v),count(0)
		{
			for(int i=0;i<26;i++)
				node[i]=NULL;
		}
		~TreeNode()
		{
			for(int i=0;i<26;i++)
				if(node[i]!=NULL)
					delete node[i];
		}
	};

	TreeNode* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root=new TreeNode('\0');
    }

	~Trie()
	{
		if(root!=NULL)
			delete root;
	}
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TreeNode* tmp=root;
		for(int i=0;i<(int)word.length();i++)
		{
			int index=word[i]-'a';
			if(tmp->node[index]==NULL)
			{
				tmp->node[index]=new TreeNode(word[i]);
			}
			tmp=tmp->node[index];
		}
		tmp->count++;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
		TreeNode* tmp=root;
        for(int i=0;i<(int)word.length();i++)
		{
			int index=word[i]-'a';
			if(tmp->node[index]==NULL)
				return false;
			tmp=tmp->node[index];
		}
		return tmp->count>0;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TreeNode* tmp=root;
		for(int i=0;i<(int)prefix.length();i++)
		{
			int index=prefix[i]-'a';
			if(tmp->node[index]==NULL)
				return false;
			tmp=tmp->node[index];
		}
		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
