#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/*
Hierholzer's Algorithm
*/

class Solution
{
public:
	vector<vector<int>> validArrangement(vector<vector<int>> &pairs)
	{
		unordered_map<int, vector<int>> graph;
		//indegree - outdegree  -1 means start node, 1 means end node
		unordered_map<int, int> degree;
		for (auto &p : pairs)
		{
			graph[p[0]].push_back(p[1]);
			++degree[p[1]];
			--degree[p[0]];
		}
		int start = pairs[0][0]; // Start anywhere if it's an Eulerian cycle
		for (auto [node, d] : degree)
		{
			if (d == -1)
			{
				start = node;
				break;
			}
		}

		//Hierholzer's Algorithm

		// Maintain a stack to keep vertices
		stack<int> curr_path;
		// vector to store final circuit
		vector<int> circuit;
		curr_path.push(start);
		int curr_v = start; // Current vertex
		while (!curr_path.empty())
		{
			if (graph[curr_v].empty())
			{
				circuit.push_back(curr_v);
				curr_v = curr_path.top();
				curr_path.pop();
			}
			else
			{
				curr_path.push(curr_v);
				int next_v = graph[curr_v].back(); //Find the next vertex
				graph[curr_v].pop_back();
				curr_v = next_v;
			}
		}

		int N = circuit.size();
		vector<vector<int>> res;
		for (int i = N - 2; i >= 0; --i)
			res.push_back({circuit[i + 1], circuit[i]});
		return res;
	}
};