#include <vector>
using namespace std;

class Solution
{
public:
	bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
	{
		vector<int> indegree(n);
		for (int i = 0; i < n; ++i)
		{
			if (leftChild[i] != -1)
				++indegree[leftChild[i]];
			if (rightChild[i] != -1)
				++indegree[rightChild[i]];
		}
		int count = 0, rootid = -1;
		for (int i = 0; i < n; ++i)
		{
			if (indegree[i] > 1)
				return false;
			if (indegree[i] == 0)
			{
				++count;
				rootid = i;
			}
		}
		if (count != 1)
			return false;
		vector<int> seen(n);
		if (!dfs(rootid, leftChild, rightChild, seen))
			return false;
		for (int i = 0; i < n; ++i)
		{
			if (seen[i] == 0)
				return false;
		}
		return true;
	}

	bool dfs(int id, vector<int> &leftChild, vector<int> &rightChild, vector<int> &seen)
	{
		seen[id] = 1;
		return (leftChild[id] == -1 || (seen[leftChild[id]] == 0 && dfs(leftChild[id], leftChild, rightChild, seen))) &&
			   (rightChild[id] == -1 || (seen[rightChild[id]] == 0 && dfs(rightChild[id], leftChild, rightChild, seen)));
	}
};