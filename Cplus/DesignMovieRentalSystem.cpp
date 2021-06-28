#include <map>
#include <set>
#include <vector>
using namespace std;

class MovieRentingSystem
{
public:
	MovieRentingSystem(int n, vector<vector<int>> &entries)
	{
		for (auto &e : entries)
		{
			data[{e[0], e[1]}] = e[2];
			unrented[e[1]].insert({e[2], e[0]});
		}
	}

	vector<int> search(int movie)
	{
		auto iter = unrented.find(movie);
		if (iter == unrented.end())
			return {};
		vector<int> res;
		auto iter1 = iter->second.begin();
		for (int i = 0; i < 5 && iter1 != iter->second.end(); ++i, ++iter1)
			res.push_back(iter1->second);
		return res;
	}

	void rent(int shop, int movie)
	{
		int price = data[{shop, movie}];
		rented.insert({price, movie, shop});
		unrented[movie].erase({price, shop});
	}

	void drop(int shop, int movie)
	{
		int price = data[{shop, movie}];
		rented.erase({price, movie, shop});
		unrented[movie].insert({price, shop});
	}

	vector<vector<int>> report()
	{
		vector<vector<int>> res;
		int i = 0;
		for (auto [p, m, s] : rented)
		{
			if (++i > 5)
				break;
			res.push_back({s, m});
		}
		return res;
	}

private:
	map<pair<int, int>, int> data;			//{{shop,movie},price}
	set<tuple<int, int, int>> rented;		//{price,movie,shop}
	map<int, set<pair<int, int>>> unrented; //{movie,{price,shop}}
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */