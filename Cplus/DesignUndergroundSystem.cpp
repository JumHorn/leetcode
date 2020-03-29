#include <string>
#include <unordered_map>
using namespace std;

class UndergroundSystem
{
public:
	UndergroundSystem()
	{
	}

	void checkIn(int id, string stationName, int t)
	{
		m[id] = {stationName, t};
	}

	void checkOut(int id, string stationName, int t)
	{
		auto tmp = avg[m[id].first][stationName];
		avg[m[id].first][stationName] = {tmp.first + t - m[id].second, tmp.second + 1};
		m.erase(id);
	}

	double getAverageTime(string startStation, string endStation)
	{
		auto tmp = avg[startStation][endStation];
		return tmp.first * 1.0 / tmp.second;
	}

private:
	unordered_map<string, unordered_map<string, pair<int, int>>> avg;  //{startStation,{endStation,{all time,passage count}}}
	unordered_map<int, pair<string, int>> m;						   //{id,{station,time}}
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
