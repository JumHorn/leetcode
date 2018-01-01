#include<iostream>
#include<vector>
using namespace std;


// 对于某一个位置，要是前一个位置“停”，则这个位置可“停”，可“不停”；要是前一个位置“不停”，则这个位置必须“停”
// 换句话说，也就是当前位置“停”，前一位置可“停”或“不停”；当前位置“不停”，前一位置必须“停”
// 用p表示该位置“停”的累加和，np表示该位置“不停”的累加和，则 p(i) = min(p(i-1), np(i-1)) + cost(i); np(i) = p(i-1) 

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int p = cost[0],np = 0,temp = 0;
        for (int i=1; i<cost.size(); ++i) {
            temp = (p>np?np:p) + cost[i];
            np = p;
            p = temp;
        }
        return p>np?np:p;
    }
};