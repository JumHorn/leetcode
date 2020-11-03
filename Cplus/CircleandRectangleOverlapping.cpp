class Solution
{
public:
	bool checkOverlap(int radius, int x_center, int y_center, int x1, int y1, int x2, int y2)
	{
		//center in rectangle
		if (x_center >= x1 && x_center <= x2 && y_center >= y1 && y_center <= y2)
			return true;
		return minDistanceToLine(x_center, y_center, x1, y1, x1, y2, radius) ||
			   minDistanceToLine(x_center, y_center, x1, y2, x2, y2, radius) ||
			   minDistanceToLine(x_center, y_center, x2, y2, x2, y1, radius) ||
			   minDistanceToLine(x_center, y_center, x2, y1, x1, y1, radius);
	}

	//the minimum distance from point (x,y) to line (x1,y1) (x2,y2)
	bool minDistanceToLine(int x, int y, int x1, int y1, int x2, int y2, int radius)
	{
		int a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2); //line square
		int b = (x - x1) * (x2 - x1) + (y - y1) * (y2 - y1);   //vector a*b
		if (a == 0)
			return b <= radius * radius;
		double t = b * 1.0 / a;
		if (t < 0)
			t = 0;
		else if (t > 1)
			t = 1;
		double mindistance = ((x - x1) - t * (x2 - x1)) * ((x - x1) - t * (x2 - x1)) +
							 ((y - y1) - t * (y2 - y1)) * ((y - y1) - t * (y2 - y1));
		return mindistance <= radius * radius;
	}
};