#include<vector>
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
    vector<int> postorder(Node* root) {
        vector<int> res;
		preorder(res,root);
		return res;
    }

	void preorder(vector<int>& res,Node* n)
	{
		if(n==NULL)
			return;
		for(int i=0;i<(int)n->children.size();i++)
			preorder(res,n->children[i]);
		res.push_back(n->val);
	}
};

