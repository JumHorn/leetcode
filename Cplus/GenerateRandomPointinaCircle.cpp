#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	Solution(double radius, double x_center, double y_center)
	{
		m_x = x_center;
		m_y = y_center;
		m_radius = radius;
		m_pi = 3.141592653;
	}

	vector<double> randPoint()
	{
		double angle = rand() % 10000 / 10000.0;
		double r = sqrt(rand() % 10000 / 10000.0);
		return {r * cos(angle * m_pi * 2) * m_radius + m_x, r * sin(angle * m_pi * 2) * m_radius + m_y};
	}

private:
	double m_pi;
	double m_x;
	double m_y;
	double m_radius;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */
