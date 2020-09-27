#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class ThroneInheritance
{
public:
	ThroneInheritance(string kingName)
	{
		tree[kingName] = {};
		root = kingName;
	}

	void birth(string parentName, string childName)
	{
		tree[parentName].push_back(childName);
	}

	void death(string name)
	{
		dead.insert(name);
	}

	vector<string> getInheritanceOrder()
	{
		vector<string> res;
		dfs(root, res);
		return res;
	}

	void dfs(string &name, vector<string> &res)
	{
		if (dead.find(name) == dead.end())
			res.push_back(name);
		for (auto &str : tree[name])
			dfs(str, res);
	}

private:
	unordered_map<string, vector<string>> tree; //{parentName,childrenName}
	unordered_set<string> dead;
	string root;
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */