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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return vector<TreeNode*>();
        vector<int> v(n);
		for(int i=0;i<n;i++)
			v[i]=i+1;
		vector<vector<int> > permutation;
		vector<int> tmp;
		generateTrees(permutation,v,tmp,0);
		vector<TreeNode*> res;
		for(int i=0;i<(int)permutation.size();i++)
		{
			TreeNode* tmp=createTree(permutation[i]);
			int j;
			for(j=0;j<(int)res.size();j++)
				if(isSame(res[j],tmp))
					break;
			if(j==(int)res.size())
				res.push_back(tmp);
		}
		return res;
    }

	bool isSame(TreeNode* t1,TreeNode* t2)
	{
		if(t1==NULL&&t2==NULL)
			return true;
		if(t1==NULL||t2==NULL)
			return false;
		return t1->val==t2->val&&isSame(t1->left,t2->left)&&isSame(t1->right,t2->right);
	}

	TreeNode* createTree(vector<int> node)
	{
		TreeNode* root=new TreeNode(node[0]);
		for(int i=1;i<(int)node.size();i++)
		{
			TreeNode* tmp=root;
			while(true)
			{
				if(node[i]>tmp->val)
				{
					if(tmp->right==NULL)
					{
						tmp->right=new TreeNode(node[i]);
						break;
					}
					else
						tmp=tmp->right;
				}
				else
				{
					if(tmp->left==NULL)
					{
						tmp->left=new TreeNode(node[i]);
						break;
					}
					else
						tmp=tmp->left;
				}
			}

		}
		return root;
	}

	void generateTrees(vector<vector<int> >& permutation,vector<int>& v,vector<int>& tmp,int start)
	{
		if(tmp.size()==v.size())
		{
			permutation.push_back(tmp);
			return;
		}
		for(int i=start;i<(int)v.size();i++)
		{
			swap(v[start],v[i]);
			tmp.push_back(v[start]);
			generateTrees(permutation,v,tmp,start+1);
			tmp.pop_back();
			swap(v[start],v[i]);
		}
	}
};
