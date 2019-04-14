#include<vector>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
		//get hieght
		int layer=0;
		Node* tmp=root;
		while(tmp!=NULL)
		{
			layer++;
			tmp=tmp->left;
		}
		vector<Node*> nodemap(layer+1,NULL);
		connect(root,0,nodemap);
		return root;        
    }

	void connect(Node* root,int layer,vector<Node*>& nodemap)
	{
		if(root==NULL)
			return;
		root->next=nodemap[layer];
		nodemap[layer]=root;
		connect(root->right,layer+1,nodemap);
		connect(root->left,layer+1,nodemap);
	}
};
