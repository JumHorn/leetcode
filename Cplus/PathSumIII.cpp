#include<iostream>
#include<stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int result=0;
        stack<TreeNode*> s;
		TreeNode* node=root;
		while(node||!s.empty())
		{
			result+=hasPathSum(node,sum);
			s.push(node);
			node=node->left;
			while(!node&&!s.empty())
			{
				node=s.top();
				node=node->right;
				s.pop();
			}
		}
		return result;
    }
    int hasPathSum(struct TreeNode *root, int sum) {
        if (root == NULL) return 0;
        // if (root->val == sum) return 1+hasPathSum(root->left, sum-root->val) + hasPathSum(root->right, sum-root->val);
        // return hasPathSum(root->left, sum-root->val) + hasPathSum(root->right, sum-root->val);
        // 化简为下面的一步,由于将加法和判断和在一起，速度提高很多
        return (root->val==sum) + hasPathSum(root->left, sum-root->val) + hasPathSum(root->right, sum-root->val);
    }
};

//other methode
class Solution0 {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root) return 0;
        return sumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
private:
    int sumUp(TreeNode* root, int pre, int& sum){
        if(!root) return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
