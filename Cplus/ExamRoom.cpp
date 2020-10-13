#include <algorithm>
#include <set>
using namespace std;

class ExamRoom
{
public:
	ExamRoom(int N)
	{
		size = N;
	}

	int seat()
	{
		if (student.empty())
		{
			student.insert(0);
			return 0;
		}
		auto iter = student.begin();
		int pre = *iter, d = -1, res = size - 1;
		for (++iter; iter != student.end(); ++iter)
		{
			if (*iter - pre > 1)
			{
				int emptyseat = (*iter - pre) / 2 + pre;
				if (emptyseat - pre > d)
				{
					d = emptyseat - pre;
					res = emptyseat;
				}
			}
			pre = *iter;
		}
		--iter;
		if (size - 1 - *iter > d)
		{
			d = size - 1 - *iter;
			res = size - 1;
		}
		iter = student.begin();
		if (*iter >= d)
		{
			d = *iter;
			res = 0;
		}
		student.insert(res);
		return res;
	}

	void leave(int p)
	{
		student.erase(p);
	}

private:
	set<int> student;
	int size;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */