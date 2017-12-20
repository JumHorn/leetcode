#include<iostream>
#include<vector>
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
    TreeNode* head;
    vector<int> *nums;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0)
        {
            return NULL;
        }
        this->nums=&nums;
        construct(0,nums.size()-1,head,0);
        return head;
    }
    
    void construct(int left,int right,TreeNode* node,int child)
    {
        if(left>right)
        {
            return;
        }
        if(left==right)
        {
            if(child==1)
            {
                node->left=new TreeNode((*nums)[left]);
            }
            else if(child==2)
            {
                node->right=new TreeNode((*nums)[left]);
            }
            else
            {
                head=new TreeNode((*nums)[left]);
            }
            return;
        }
        int max,temp=-2147483648;
        for(int i=left;i<=right;i++)
        {
            if((*nums)[i]>temp)
            {
                temp=(*nums)[i];
                max=i;
            }
        }
        if(child==1)
        {
            node->left=new TreeNode((*nums)[max]);
            construct(left,max-1,node->left,1);
            construct(max+1,right,node->left,2);
        }
        else if(child==2)
        {
            node->right=new TreeNode((*nums)[max]);
            construct(left,max-1,node->right,1);
            construct(max+1,right,node->right,2);
        }
        else
        {
            head=new TreeNode((*nums)[max]);
            construct(left,max-1,head,1);
            construct(max+1,right,head,2);
        }
    }
};

// public class Solution {
//     public TreeNode constructMaximumBinaryTree(int[] nums) {
//         return construct(nums, 0, nums.length);
//     }
//     public TreeNode construct(int[] nums, int l, int r) {
//         if (l == r)
//             return null;
//         int max_i = max(nums, l, r);
//         TreeNode root = new TreeNode(nums[max_i]);
//         root.left = construct(nums, l, max_i);
//         root.right = construct(nums, max_i + 1, r);
//         return root;
//     }
//     public int max(int[] nums, int l, int r) {
//         int max_i = l;
//         for (int i = l; i < r; i++) {
//             if (nums[max_i] < nums[i])
//                 max_i = i;
//         }
//         return max_i;
//     }
// }