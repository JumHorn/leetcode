#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> exclusiveTime(int n, vector<string> &logs)
	{
		vector<int> res(n);
		stack<Function> s;
		for (int i = 0; i < (int)logs.size(); i++)
		{
			int j = 0;
			Function tmp;
			while (logs[i][j] != ':')
				j++;
			tmp.id = stoi(logs[i].substr(0, j));
			int k = ++j;
			while (logs[i][k] != ':')
				k++;
			bool state = (logs[i].substr(j, k - j) == "start");
			if (state)
			{
				tmp.start = stoi(logs[i].substr(k + 1));
				s.push(tmp);
			}
			else
			{
				s.top().end = stoi(logs[i].substr(k + 1));
				tmp = s.top();
				s.pop();
				int time = tmp.end - tmp.start + 1;
				res[tmp.id] += time - tmp.sched;
				if (!s.empty())
					s.top().sched += time;
			}
		}
		// while (!s.empty())
		// {
		// 	int time = s.top().end - s.top().start + 1;
		// 	res[s.top().id] = time - s.top().sched;
		// 	s.pop();
		// 	if (!s.empty())
		// 		s.top().sched += time;
		// }
		return res;
	}

private:
	struct Function
	{
		Function() : start(0), end(0), id(0), sched(0) {}
		int start;
		int end;
		int id;
		int sched; //schedule time
	};
};