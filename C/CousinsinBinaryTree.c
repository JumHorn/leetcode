

//Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void dfs(struct TreeNode* root,int x,int y,int depth,int(*p)[2])
{
	if(root->left)
	{
		if(root->left->val==x)
		{
			p[0][0]=root->val;
			p[0][1]=depth;
		}
		else if(root->left->val==y)
		{
			p[1][0]=root->val;
			p[1][1]=depth;
		}
		dfs(root->left,x,y,depth+1,p);
	}
	if(root->right)
	{
		if(root->right->val==x)
		{
			p[0][0]=root->val;
			p[0][1]=depth;
		}
		else if(root->right->val==y)
		{
			p[1][0]=root->val;
			p[1][1]=depth;
		}
		dfs(root->right,x,y,depth+1,p);
	}
}

bool isCousins(struct TreeNode* root, int x, int y){
	if(!root||root->val==x||root->val==y)
		return false;
	int node[2][2];
	dfs(root,x,y,0,node);
	return node[0][0]!=node[1][0]&&node[0][1]==node[1][1];
}

