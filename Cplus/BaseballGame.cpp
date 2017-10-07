#include<iostream>
#include<vector>
#include<string>
#include<cstdlib>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> round;
        int sum=0,temp;
        for(vector<string>::iterator iter=ops.begin();iter!=ops.end();iter++)
        {
            switch(ToInteger(*iter))
            {
                case 30001:
                sum-=round[round.size()-1];
                round.pop_back();
                break;

                case 30002:
                temp=2*round[round.size()-1];
                sum+=temp;
                round.push_back(temp);
                break;

                case 30003:
                temp=round[round.size()-1]+round[round.size()-2];
                sum+=temp;
                round.push_back(temp);
                break;

                default:
                temp=ToInteger(*iter);
                round.push_back(temp);
                sum+=temp;
            }
        }
        return sum;
    }
    int ToInteger(string &s)
    {
        if(s=="C")
        {
            return 30001;
        }
        else if(s=="D")
        {
            return 30002;
        }
        else if(s=="+")
        {
            return 30003;
        }
        else
        {
            return atoi(s.c_str());
        }
    }
};