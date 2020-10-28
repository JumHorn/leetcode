#include <unordered_map>
#include <vector>
using namespace std;

// Employee info
class Employee
{
public:
	// It's the unique ID of each node.
	// unique id of this employee
	int id;
	// the importance value of this employee
	int importance;
	// the id of direct subordinates
	vector<int> subordinates;
};

class Solution
{
public:
	int getImportance(vector<Employee *> employees, int id)
	{
		unordered_map<int, Employee *> m; //{id,Employee}
		for (int i = 0; i < (int)employees.size(); ++i)
			m[employees[i]->id] = employees[i];
		return dfs(id, m);
	}

	int dfs(int id, unordered_map<int, Employee *> &m)
	{
		int res = m[id]->importance;
		for (auto employeeid : m[id]->subordinates)
			res += dfs(employeeid, m);
		return res;
	}
};