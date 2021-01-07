#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class CBTInserter
{
public:
	CBTInserter(TreeNode *root) : m_root(root)
	{
		m_q.push(root);
		while (true)
		{
			TreeNode *tmp = m_q.front();
			if (tmp->left == nullptr || tmp->right == nullptr)
				break;
			m_q.pop();
			m_q.push(tmp->left);
			if (tmp->right != nullptr)
				m_q.push(tmp->right);
		}
	}

	int insert(int v)
	{
		TreeNode *tmp = m_q.front();
		if (tmp->left == nullptr)
		{
			tmp->left = new TreeNode(v);
			return tmp->val;
		}
		tmp->right = new TreeNode(v);
		m_q.pop();
		m_q.push(tmp->left);
		m_q.push(tmp->right);
		return tmp->val;
	}

	TreeNode *get_root()
	{
		return m_root;
	}

private:
	TreeNode *m_root;
	queue<TreeNode *> m_q;
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */