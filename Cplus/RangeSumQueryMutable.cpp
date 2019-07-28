#include<vector>
#include<iostream>
using namespace std;

class NumArray {
private:
	struct TreeNode
	{
		int l,r,sum;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int x,int y,int z=0):l(x),r(y),sum(z),left(NULL),right(NULL){}
	};

	TreeNode* root;
	vector<int>& data;

	void buildTree(TreeNode* root)
	{
		if(root==NULL||root->r-root->l<=1)
			return;
		root->left=new TreeNode(root->l,root->l+(root->r-root->l)/2);
		buildTree(root->left);
		root->right=new TreeNode(root->l+(root->r-root->l)/2,root->r);
		buildTree(root->right);
	}

	int calcSum(TreeNode* root)
	{
		if(root==NULL)
			return 0;
		if(root->left==NULL&&root->right==NULL)
			root->sum=data[root->l];
        else
		    root->sum=calcSum(root->left)+calcSum(root->right);
		return root->sum;
	}

	int query(int i) const
	{
		if(i<0)
			return 0;
		TreeNode* tmp=root;
		int res=0;
		while(tmp!=NULL)
		{
			if(i==tmp->r-1)
			{
				res+=tmp->sum;
				break;
			}
			int mid=(tmp->r-tmp->l)/2+tmp->l;
			if(i<mid)
				tmp=tmp->left;
			else
			{
				res+=tmp->left->sum;
				tmp=tmp->right;
			}
		}
		return res;
	}

public:
    NumArray(vector<int>& nums): data(nums){
        if(!nums.empty())
        {
            root=new TreeNode(0,nums.size());
            buildTree(root);
            calcSum(root);
        }
    }
    
    void update(int i, int val) {
        int delta=val-data[i];
		data[i]=val;
		TreeNode* tmp=root;
		while(tmp!=NULL)
		{
			tmp->sum+=delta;
			int mid=(tmp->r-tmp->l)/2+tmp->l;
			if(i<mid)
				tmp=tmp->left;
			else
				tmp=tmp->right;
		}
    }
    
    int sumRange(int i, int j) {
 		return query(j)-query(i-1); 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */