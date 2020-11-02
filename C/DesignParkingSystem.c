#include <stdbool.h>
#include <stdlib.h>

typedef struct
{
	int sys[4];
} ParkingSystem;

ParkingSystem* parkingSystemCreate(int big, int medium, int small)
{
	ParkingSystem* system = (ParkingSystem*)malloc(sizeof(ParkingSystem));
	system->sys[1] = big;
	system->sys[2] = medium;
	system->sys[3] = small;
	return system;
}

bool parkingSystemAddCar(ParkingSystem* obj, int carType)
{
	if (obj->sys[carType] <= 0)
		return false;
	--obj->sys[carType];
	return true;
}

void parkingSystemFree(ParkingSystem* obj)
{
	if (obj)
		free(obj);
}

/**
 * Your ParkingSystem struct will be instantiated and called as such:
 * ParkingSystem* obj = parkingSystemCreate(big, medium, small);
 * bool param_1 = parkingSystemAddCar(obj, carType);
 
 * parkingSystemFree(obj);
*/
