#include<string>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
		int index=findDash(S,0);
		TreeNode* root=new TreeNode(stoi(S.substr(0,index)));
    	buildTree(S,index,1,root);   
		return root;
    }

	int buildTree(const string& s,int index,int layer,TreeNode* root)
	{
		if(index>=(int)s.length())
			return index;
		int i=countDash(s,index);
        int dash=i-index;
		int tmp=findDash(s,i);
		if(dash==layer)
		{
			root->left=new TreeNode(stoi(s.substr(i,tmp-i)));
			index=tmp;
			index=buildTree(s,index,layer+1,root->left);
            if(index>=(int)s.length())
				return index;

            i=countDash(s,index);
            dash=i-index;
            tmp=findDash(s,i);
            if(dash==layer)
            {
                root->right=new TreeNode(stoi(s.substr(i,tmp-i)));
                index=tmp;
                index=buildTree(s,index,layer+1,root->right);
            }
		}
		return index;
	}

	int findDash(const string& s,int i)
	{
		while(i<(int)s.length()&&s[i]!='-')
			i++;
		return i;
	}

	int countDash(const string& s,int i)
	{
		while(s[++i]=='-');
		return i;
	}
};