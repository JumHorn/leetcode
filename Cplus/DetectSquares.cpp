#include <vector>
using namespace std;

class DetectSquares
{
public:
	DetectSquares() : data(2000000)
	{
	}

	void add(vector<int> point)
	{
		int x = point[0], y = point[1];
		++data[encode(x, y)];
	}

	int count(vector<int> point)
	{
		int x = point[0], y = point[1], res = 0;
		//左下
		for (int l = 1; x - l >= 0 && y - l >= 0; ++l)
		{
			int p1 = x - l, p2 = y - l;
			int q1 = p1, q2 = y;
			int r1 = x, r2 = p2;
			res += data[encode(p1, p2)] * data[encode(q1, q2)] * data[encode(r1, r2)];
		}
		//右上
		for (int l = 1; x + l < LEN && y + l < LEN; ++l)
		{
			int p1 = x + l, p2 = y + l;
			int q1 = x, q2 = p2;
			int r1 = p1, r2 = y;
			res += data[encode(p1, p2)] * data[encode(q1, q2)] * data[encode(r1, r2)];
		}
		//左上
		for (int l = 1; x - l >= 0 && y + l < LEN; ++l)
		{
			int p1 = x - l, p2 = y + l;
			int q1 = p1, q2 = y;
			int r1 = x, r2 = p2;
			res += data[encode(p1, p2)] * data[encode(q1, q2)] * data[encode(r1, r2)];
		}
		//右下
		for (int l = 1; x + l < LEN && y - l >= 0; ++l)
		{
			int p1 = x + l, p2 = y - l;
			int q1 = x, q2 = p2;
			int r1 = p1, r2 = y;
			res += data[encode(p1, p2)] * data[encode(q1, q2)] * data[encode(r1, r2)];
		}
		return res;
	}

	int encode(int x, int y)
	{
		return x * LEN + y;
	}

private:
	int LEN = 1001;
	vector<int> data; // x*1001+y
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */