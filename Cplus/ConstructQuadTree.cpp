#include<vector>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
		return construct(grid,0,0,grid.size(),grid.size());        
    }

	Node* construct(vector<vector<int>>& grid,int top,int left,int bottom,int right)
	{
		Node* root=new Node(true,false,NULL,NULL,NULL,NULL);
		if(right-left<=1&&bottom-top<=1)
		{
			root->isLeaf=true;
			root->val=grid[top][left]==1;
			return root;
		}
		root->topLeft=construct(grid,top,left,top+(bottom-top)/2,left+(right-left)/2);
		root->topRight=construct(grid,top,left+(right-left)/2,top+(bottom-top)/2,right);
		root->bottomLeft=construct(grid,top+(bottom-top)/2,left,bottom,left+(right-left)/2);
		root->bottomRight=construct(grid,top+(bottom-top)/2,left+(right-left)/2,bottom,right);
		if(root->topLeft->isLeaf&&root->topRight->isLeaf&&root->bottomLeft->isLeaf&&root->bottomRight->isLeaf)
		{
			if(root->topLeft->val==root->topRight->val&&root->topLeft->val==root->bottomLeft->val&&root->topLeft->val==root->bottomRight->val)
			{
				root->isLeaf=true;
				root->val=root->topLeft->val;
				root->topLeft=root->topRight=root->bottomLeft=root->bottomRight=NULL;
				return root;
			}
		}
		root->isLeaf=false;
		return root;
	}
};
