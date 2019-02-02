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
    int maxDepth(Node* root) {
        if(root==NULL)
			return 0;
		int level=0;
		for(int i=0;i<(int)root->children.size();i++)
		{
			level=max(level,maxDepth(root->children[i]));
		}
		return level+1;
    }
};
