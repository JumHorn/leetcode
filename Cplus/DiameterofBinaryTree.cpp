#include<iostream>
#include<algorithm>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int result=0,temp;
		int diameterOfBinaryTree(TreeNode* root) {
			if(!root)
			{
				return 0;
			}
			temp=maxlevel(root->left,0)+maxlevel(root->right,0);
			if(result<temp)
			{
				result = temp; 
			}
			diameterOfBinaryTree(root->left);
			diameterOfBinaryTree(root->right);
			return result;
		}

		int maxlevel(TreeNode* root,int level)
		{
			if(!root)
			{
				return level;
			}
			return max(maxlevel(root->left,level+1),maxlevel(root->right,level+1));
		}
};

//认为顶点的两段的层数就是最大层数，忽略了其他节点
class Solution0 {
	public:
		int diameterOfBinaryTree(TreeNode* root) {
			if(!root)
			{
				return 0;
			}
			return maxlevel(root->left,1)+maxlevel(root->right,1)-2;
		}

		int maxlevel(TreeNode* root,int level)
		{
			if(!root)
			{
				return level;
			}
			return max(maxlevel(root->left,level+1),maxlevel(root->right,level+1));
		}
};


// public class Solution {
//     int max = 0;
    
//     public int diameterOfBinaryTree(TreeNode root) {
//         maxDepth(root);
//         return max;
//     }
    
//     private int maxDepth(TreeNode root) {
//         if (root == null) return 0;
        
//         int left = maxDepth(root.left);
//         int right = maxDepth(root.right);
        
//         max = Math.max(max, left + right);
        
//         return Math.max(left, right) + 1;
//     }
// }