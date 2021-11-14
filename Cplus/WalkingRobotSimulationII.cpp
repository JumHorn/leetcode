#include <string>
#include <vector>
using namespace std;

class Robot
{
public:
	Robot(int width, int height)
	{
		dir = {"East", "North", "West", "South"};
		d = 0;
		w = width;
		h = height;
		x = 0;
		y = 0;
	}

	void move(int num)
	{
		num %= (w * 2 + h * 2 - 4);
		num += (w * 2 + h * 2 - 4); //face 朝向如果是初始位置一个周期，那么应该是south，偷懒了，所以这么写
		while (num > 0)
		{
			bool turn = false;
			if (d == 0)
			{
				if (num > w - x - 1)
					turn = true;
				int val = min(w - x - 1, num);
				x += val;
				num -= val;
			}
			else if (d == 1)
			{
				if (num > h - y - 1)
					turn = true;
				int val = min(h - y - 1, num);
				y += val;
				num -= val;
			}
			else if (d == 2)
			{
				if (num > x)
					turn = true;
				int val = min(x, num);
				num -= val;
				x -= val;
			}
			else
			{
				if (num > y)
					turn = true;
				int val = min(y, num);
				num -= val;
				y -= val;
			}
			if (turn)
				d = (d + 1) % 4;
		}
	}

	vector<int> getPos()
	{
		return {x, y};
	}

	string getDir()
	{
		return dir[d];
	}

private:
	vector<string> dir;
	int d, w, h, x, y;
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->move(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */