//   Definition for a binary tree node
class TreeNode
{
	int val;
	TreeNode left;
	TreeNode right;
	TreeNode(int x){val = x;}
}

public class MaximumDepthofBinaryTree
{
	public int maxDepth(TreeNode root) {
		if(root == null)
			return 0;
		return 1 + max(maxDepth(root.left), maxDepth(root.right));
	}
	int max(int a,int b)
	{
		if(a>b)
			return a;
		else 
			return b;
	}
}
