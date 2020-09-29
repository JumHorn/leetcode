#include <cstdlib>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(int n_rows, int n_cols)
	{
		rows = n_rows;
		cols = n_cols;
		total = n_rows * n_cols;
	}

	vector<int> flip()
	{
		int i = rand() % total--, res = i;
		if (m.find(i) != m.end())
			res = m[i];
		m[i] = total;
		if (m.find(total) != m.end())
			m[i] = m[total];
		m[total] = res;
		return {res / cols, res % cols};
	}

	void reset()
	{
		total = rows * cols;
	}

private:
	int rows;
	int cols;
	int total;
	unordered_map<int, int> m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */