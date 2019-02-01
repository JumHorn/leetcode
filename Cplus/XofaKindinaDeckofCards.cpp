#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        map<int,int> statistics;
		for(int i=0;i<(int)deck.size();i++)
			statistics[deck[i]]++;
		int tmp=statistics.begin()->second;
        for(map<int,int>::iterator iter=statistics.begin();iter!=statistics.end();iter++)
        {
			tmp=GreatestCommonDivisor(tmp,iter->second);
        }
		return true;
    }

	int GreatestCommonDivisor(int x,int y)
	{
		return x == 0 ? y : GreatestCommonDivisor(y%x, x);
	}
};
