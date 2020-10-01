#include <algorithm>
#include <sstream>
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
		for (auto &log : logs)
		{
			Function func;
			stringstream ss(log);
			string token;
			getline(ss, token, ':');
			func.id = stoi(token);
			getline(ss, token, ':');
			bool state = (token == "start");
			getline(ss, token, ':');
			if (state)
			{
				func.start = stoi(token);
				s.push(func);
			}
			else
			{
				s.top().end = stoi(token);
				func = s.top();
				s.pop();
				int time = func.end - func.start + 1;
				res[func.id] += time - func.sched;
				if (!s.empty())
					s.top().sched += time;
			}
		}
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