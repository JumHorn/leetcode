#include<vector>
#include<string>
using namespace std;

class Solution {
	struct TreeNode
	{
		int count;
		vector<TreeNode*> node;
		TreeNode():count(0),node(26)
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
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root=new TreeNode();
		for(int i=0;i<(int)words.size();i++)
			insert(words[i]);
		root->count=0;
		vector<string> res;
		for(int i=0;i<(int)words.size();i++)
			if(search(words[i],0)>1)
				res.push_back(words[i]);
		return res;
    }

	int search(const string& str,int index)
	{
		int res=0;
		TreeNode* tmp=root;
		for(int i=index;i<(int)str.length();i++)
		{
			tmp=tmp->node[str[i]-'a'];
			if(tmp==NULL)
				return -1;
			if(tmp->count>0)
			{
				res++;
				if(search(str,i+1)!=-1)
					return ++res;
				res--;
			}
		}
		if(tmp->count==0)
			return -1;
		return res;
	}
	
	void insert(const string& str)
	{
		TreeNode* tmp=root;
		for(int i=0;i<(int)str.length();i++)
		{
			int index=str[i]-'a';
			if(tmp->node[index]==NULL)
				tmp->node[index]=new TreeNode();
			tmp=tmp->node[index];
		}
		++tmp->count;
	}
};
