#include <vector>
using namespace std;

class ParkingSystem
{
public:
	ParkingSystem(int big, int medium, int small) : sys(4)
	{
		sys[1] = big;
		sys[2] = medium;
		sys[3] = small;
	}

	bool addCar(int carType)
	{
		if (sys[carType] <= 0)
			return false;
		--sys[carType];
		return true;
	}

private:
	vector<int> sys;
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */