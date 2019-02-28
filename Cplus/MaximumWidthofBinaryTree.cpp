#include<vector>
#include<algorithm>
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
    int widthOfBinaryTree(TreeNode* root) {
		int res=0;
		if(root==NULL)
			return res;		
		res=1;
		vector<TreeNode*> *v=new vector<TreeNode*>(1,root);
		vector<TreeNode*> *tmp=new vector<TreeNode*>();
		//乒乓操作
		while(!v->empty()||!tmp->empty())
		{
			for(int i=0;i<(int)v->size();i++)
			{
				if((*v)[i]!=NULL)
				{
					if((*v)[i]->left==NULL)
					{
						if(!tmp->empty())
							tmp->push_back((*v)[i]->left);
					}
					else
						tmp->push_back((*v)[i]->left);

					if((*v)[i]->right==NULL)
					{
						if(!tmp->empty())
							tmp->push_back((*v)[i]->right);
					}
					else
						tmp->push_back((*v)[i]->right);
				}
			}
			res=max(res,calcuWidth(*tmp));
			v->clear();
			vector<TreeNode*> *s=v;
			v=tmp;
			tmp=s;
		}
		return res;
    }

	int calcuWidth(vector<TreeNode*>& v)
	{
		if(v.empty())
			return 0;
		int res=v.size()-1;
		while(v[res]==NULL)
			--res;
		return res+1;
	}
};
