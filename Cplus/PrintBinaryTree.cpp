#include<vector>
#include<string>
#include<deque>
#include<queue>
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
    vector<vector<string> > printTree(TreeNode* root) {
		vector<vector<string> > res;
		if(root==NULL)
			return res;
        queue<TreeNode*> *p=new queue<TreeNode*>();
        queue<TreeNode*> *q=new queue<TreeNode*>();
		p->push(root);
		vector<deque<string> > v;
		int layer=-1;
		bool flag=true;
		while(flag)
		{
			layer++;
			flag=false;
			deque<string> d;
			while(!p->empty())
			{
				TreeNode* node=p->front();
				if(node==NULL)
				{
					q->push(node);
					q->push(node);
					d.push_back("");
                    d.push_back("");
				}
				else
				{
                    if(node->left||node->right)
					    flag=true;
					q->push(node->left);
					q->push(node->right);
					d.push_back(to_string(node->val));
				}
				p->pop();
			}
			v.push_back(d);
			for(int i=0;i<layer;i++)
			{
				v[i].push_back("");
				v[i].push_front("");
			}
			queue<TreeNode*> *tmp=p;
			p=q;
			q=tmp;
		}
		for(int i=0;i<(int)v.size();i++)
		{
			res.emplace_back(vector<string>(v[i].begin(),v[i].end()));
		}
		return res;
    }
};
