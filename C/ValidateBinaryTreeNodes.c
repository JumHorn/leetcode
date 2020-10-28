#include <stdbool.h>
#include <string.h>

bool dfs(int id, int *leftChild, int *rightChild, int *seen)
{
	seen[id] = 1;
	return (leftChild[id] == -1 || (seen[leftChild[id]] == 0 && dfs(leftChild[id], leftChild, rightChild, seen))) &&
		   (rightChild[id] == -1 || (seen[rightChild[id]] == 0 && dfs(rightChild[id], leftChild, rightChild, seen)));
}

bool validateBinaryTreeNodes(int n, int *leftChild, int leftChildSize, int *rightChild, int rightChildSize)
{
	int indegree[n];
	memset(indegree, 0, sizeof(indegree));
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
	int seen[n];
	memset(seen, 0, sizeof(seen));
	if (!dfs(rootid, leftChild, rightChild, seen))
		return false;
	for (int i = 0; i < n; ++i)
	{
		if (seen[i] == 0)
			return false;
	}
	return true;
}
