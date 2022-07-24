#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class FoodRatings
{
public:
	FoodRatings(vector<string> &foods, vector<string> &cuisines, vector<int> &ratings)
	{
		int N = foods.size();
		for (int i = 0; i < N; ++i)
		{
			rate[foods[i]] = {ratings[i], cuisines[i]};
			cuis[cuisines[i]].insert({-ratings[i], foods[i]});
		}
	}

	void changeRating(string food, int newRating)
	{
		auto it = rate.find(food);
		if (it == rate.end())
			return;
		cuis[it->second.second].erase({-it->second.first, food});
		cuis[it->second.second].insert({-newRating, food});
		it->second.first = newRating;
	}

	string highestRated(string cuisine)
	{
		auto it = cuis.find(cuisine);
		if (it == cuis.end())
			return "";
		if (it->second.empty())
			return "";
		return it->second.begin()->second;
	}

private:
	unordered_map<string, pair<int, string>> rate;		//{food,{rating,cuisine}}
	unordered_map<string, set<pair<int, string>>> cuis; //{cuisines,{rating,food}}
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */