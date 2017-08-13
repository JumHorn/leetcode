#include<iostream>
#include<vector>
#include<queue>
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
    long sum,n;
    vector<double> res;

    void init()
    {
        sum=0;
        n=0;
    }

    void add(int val)
    {
        sum+=val;
        n++;
    }

    void save()
    {
        res.push_back(sum*1.0/n);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode *> treequeue;
        treequeue.push(root);
        res.clear();
        while(true)
        {
            init();
            queue<TreeNode *> temp;
            while(!treequeue.empty())
            {
                TreeNode * node = treequeue.front();
                if(node==NULL)
                {
                    treequeue.pop();
                    continue;
                }

                add(node->val);

                //将非空子节点插入temp
                temp.push(node->left);
                temp.push(node->right);

                treequeue.pop();
            }
            if(temp.empty())
            {
                break;
            }
            else
            {
                treequeue=temp;
            }
            save();
        }
        return res;
    }
};

//创建树的函数
/*
          3
    9           20
            15       7 
                13
*/
TreeNode* createtree()
{
    //TreeNode head(3);
    TreeNode *tree = new TreeNode(3);
    tree->left=new TreeNode(9);
    tree->right=new TreeNode(20);
    tree->right->left=new TreeNode(15);
    tree->right->right=new TreeNode(7);
    tree->right->left->right=new TreeNode(13);

    return tree;
}
void printvector(vector<double> vec)
{
    for(vector<double>::iterator iter=vec.begin();iter!=vec.end();iter++)
    {
        cout<<*iter<<",";
    }
    cout<<endl;
}
//打印树
//可以递归实现先序，中序，后序
void print(TreeNode * tree)
{
    //代码不简洁
    // if(tree->left==NULL&&tree->right==NULL)
    // {
    //     cout<<tree->val<<endl;
    //     return;
    // }
    // else if(tree->left!=NULL&&tree->right==NULL)
    // {
    //     cout<<tree->val<<endl;
    //     print(tree->left);
    // }
    // else if(tree->left==NULL&&tree->right!=NULL)
    // {
    //     cout<<tree->val<<endl;
    //     print(tree->right);
    // }
    // else
    // {
    //     cout<<tree->val<<endl;
    //     print(tree->left);
    //     print(tree->right);
    // }
    if(tree==NULL)
    {
        return ;
    }
    else
    {
        cout<<tree->val<<endl;     //先序遍历
        print(tree->left);
        print(tree->right);

        // print(tree->left);
        // cout<<tree->val<<endl;     //中序遍历
        // print(tree->right);

        // print(tree->left);
        // print(tree->right);
        // cout<<tree->val<<endl;     //后序遍历
    }
}

int main()
{
    TreeNode *head=createtree();
    print(head);
    Solution sol;
    sol.averageOfLevels(head);
    printvector(sol.res);
}