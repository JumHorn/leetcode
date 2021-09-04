#include <vector>
using namespace std;

class LockingTree
{
public:
	LockingTree(vector<int> &parent) : ancestors(parent)
	{
		int N = parent.size();
		locked = vector<int>(N); //0 means unlocked
		graph = vector<vector<int>>(N);
		for (int i = 0; i < N; ++i)
		{
			if (parent[i] != -1)
				graph[parent[i]].push_back(i);
		}
	}

	bool lock(int num, int user)
	{
		if (locked[num] != 0)
			return false;
		locked[num] = user;
		return true;
	}

	bool unlock(int num, int user)
	{
		if (locked[num] != user)
			return false;
		locked[num] = 0;
		return true;
	}

	bool upgrade(int num, int user)
	{
		if (locked[num] != 0)
			return false;
		//It does not have any locked ancestors.
		int id = num;
		while (id != -1 && ancestors[id] != -1)
		{
			id = ancestors[id];
			if (id != -1 && locked[id] != 0)
				return false;
		}

		if (!hasLock(num))
			return false;
		recursiveUnlock(num, user);
		locked[num] = user;
		return true;
	}

private:
	void recursiveUnlock(int id, int user)
	{
		if (locked[id] != 0)
			locked[id] = 0;
		for (auto n : graph[id])
			recursiveUnlock(n, user);
	}

	bool hasLock(int id)
	{
		if (locked[id] != 0)
			return true;
		for (auto n : graph[id])
		{
			if (hasLock(n))
				return true;
		}
		return false;
	}

private:
	vector<int> &ancestors;
	vector<vector<int>> graph;
	vector<int> locked; //index with userid
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */