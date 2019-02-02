#include<vector>
#include<queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int> > levelOrder(Node* root) {
        vector<vector<int> > res;
		if(root==NULL)
			return res;
		queue<Node*> q;
		q.push(root);
		levelOrder(res,q);
		return res;
    }

	void levelOrder(vector<vector<int> >& res,queue<Node*>& q)
	{
		if(q.empty())
			return;
		queue<Node*> newqueue;
		vector<int> tmp;
		while(!q.empty())
		{
			Node* node=q.front();
			q.pop();
			tmp.push_back(node->val);
			for(int i=0;i<(int)node->children.size();i++)
				newqueue.push(node->children[i]);
		}
		res.push_back(tmp);
		levelOrder(res,newqueue);
	}
};
