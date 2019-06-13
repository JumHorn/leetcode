#include<vector>
#include<string>
#include<cstring>
using namespace std;

class Solution {
	struct TreeNode
	{
		int index;
		TreeNode* node[26]; 
		TreeNode():index(-1)
		{
			memset(node,0,sizeof(node));
		}
		// ~TreeNode()
		// {
		// 	for(int i=0;i<26;i++)
		// 		if(node[i]!=NULL)
		// 			delete node[i];
		// }
	};

	TreeNode* root;
public:
    vector<vector<int> > palindromePairs(vector<string>& words) {
		vector<vector<int> > res;
		root=new TreeNode();
		for(int i=0;i<(int)words.size();i++)
			insert(words[i],i);		
		for(int i=0;i<(int)words.size();i++)
		{
			TreeNode* tmp=root;
			if(root->index>=0)
			{
				if(i!=root->index&&isPalindrome(words[i],0))
				{
					res.push_back({i,root->index});
				}
			}
			int j;
			for(j=0;j<(int)words[i].length();j++)
			{
				tmp=tmp->node[words[i][j]-'a'];
				if(tmp==NULL)
					break;
				if(tmp->index>=0&&tmp->index!=i&&isPalindrome(words[i],j+1))
					res.push_back({i,tmp->index});
			}
			if(j==(int)words[i].length()&&tmp!=NULL)
			{
				for(int k=0;k<26;k++)
					if(tmp->node[k]!=NULL)
					{
                        string s(1,k+'a');
			 			search(res,tmp->node[k],i,s);
					}
			}
		}
		return res;
    }

	void search(vector<vector<int> >& res,TreeNode* root,int first,string left)
	{
		if(root==NULL)
			return;
		if(root->index>=0)
		{
			if(isPalindrome(left,0))
				res.push_back({first,root->index});
		}
		for(int i=0;i<26;i++)
		{
			if(root->node[i]!=NULL)
			{
				left.push_back(i+'a');
				search(res,root->node[i],first,left);
				left.pop_back();
			}
		}
	}

    void insert(const string& word,int index) 
	{
		if(word.empty())
		{
			root->index=index;
			return;
		}
        TreeNode* tmp=root;
		for(int i=word.length()-1;i>=0;i--)
		{
			int j=word[i]-'a';
			if(tmp->node[j]==NULL)
			{
				tmp->node[j]=new TreeNode();
			}
			tmp=tmp->node[j];
		}
		tmp->index=index;
    }

	bool isPalindrome(const string& word,int i)
	{
		int j=word.length()-1;
		while(i<j)
			if(word[i++]!=word[j--])
				return false;
		return true;
	}
};