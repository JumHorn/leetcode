#include<vector>
#include<string>
using namespace std;

class WordDictionary {
	struct TreeNode
	{
		vector<TreeNode*> v;
		bool exist;
		TreeNode():v(26),exist(false)
		{
			for(int i=0;i<26;i++)
				v[i]=NULL;
		}
	};

	TreeNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root=new TreeNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
		TreeNode* tmp=root;
        for(int i=0;i<(int)word.length();i++)
		{
			int index=word[i]-'a';
			if(tmp->v[index]==NULL)
				tmp->v[index]=new TreeNode();
			tmp=tmp->v[index];
		}
		tmp->exist=true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
		return search(word,0,root);
    }

	bool search(const string& word,int index,TreeNode* root)
	{
        for(int i=index;i<(int)word.length();i++)
		{
			if(word[i]=='.')
			{
				for(int j=0;j<26;j++)
				{
					if(root->v[j]!=NULL)
					{
						if(search(word,i+1,root->v[j]))
							return true;
					}
				}
				return false;
			}
			int index=word[i]-'a';
			if(root->v[index]==NULL)
				return false;
			root=root->v[index];
		}
		return root->exist;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */