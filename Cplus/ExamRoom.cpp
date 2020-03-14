#include <algorithm>
#include <map>
using namespace std;

class ExamRoom
{
public:
	ExamRoom(int N)
	{
		start = -1;
		end = -1;
		m_n = N;
	}

	int seat()
	{
		if (start == -1)
		{
			start = 0;
			if (end != -1)
				m[0] = m_n - 1;
			return 0;
		}
		if (end == -1)
		{
			end = 0;
			m[0] = m_n - 1;
			return m_n - 1;
		}
		int len = 0, i;
		for (auto n : m)
		{
			int tmp = n.second - n.first;
			if (tmp % 2 == 1)
				--tmp;
			if (tmp > len)
			{
				len = tmp;
				i = n.first;
			}
		}
		if (start >= len / 2 && start >= end)
		{
			m[0] = m.begin()->first;
			start = 0;
			return 0;
		}
		if (end > len / 2 && end > start)
		{
			m[m.rbegin()->second] = m_n - 1;
			end = 0;
			return m_n - 1;
		}
		int res = i + len / 2;
		m[res] = m[i];
		m[i] = res;
		return res;
	}

	void leave(int p)
	{
		if (p == 0)
		{
			if (end == -1)
				start = -1;
			else
			{
				start = m[0];
				m.erase(0);
				if (start == m_n - 1)
					start = -1;
			}
		}
		else if (p == m_n - 1)
		{
			if (start == -1)
				end = -1;
			else
			{
				end = m_n - m.rbegin()->first - 1;
				m[m.rbegin()->first] = m.rbegin()->first;
				if (end == m_n - 1)
					end = -1;
			}
		}
		else
		{
			auto iter = m.find(p);
			if (iter == m.end())
			{
				end = m_n - m.rbegin()->first - 1;
				if (end == m_n - 1)
					end = -1;
				m.erase(--m.end());
			}
			else if (iter == m.begin())
			{
				start = iter->second;
				if (start == m_n - 1)
					start = -1;
				m.erase(iter);
			}
			else
			{
				--iter;
				m[iter->first] = m[p];
				m.erase(p);
			}
		}
	}

private:
	map<int, int> m;
	int start;
	int end;
	int m_n;
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */