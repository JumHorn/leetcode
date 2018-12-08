#include<vector>
using namespace std;

class StockSpanner {
public:
	vector<vector<int> > value;
	int res;
    StockSpanner():res(1) {
        
    }
    
    int next(int price) {
		res=1;
		int i;
        for(i=value.size()-1;i>=0;i--)
		{
			if(price>=value[i][0])
				res+=value[i][1];
			else
			{
				value.resize(i+1);
				vector<int> tmp(2);
				tmp[0]=price;
				tmp[1]=res;
				value.push_back(tmp);
				return res;
			}
		}
		if(i==-1)
			value.clear();
		vector<int> tmp(2);
		tmp[0]=price;
		tmp[1]=res;
		value.push_back(tmp);
		return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner obj = new StockSpanner();
 * int param_1 = obj.next(price);
 */
