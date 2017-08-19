#include<iostream>
#include<map>
#include<string>
using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        map<char,int> move,calcu;
        //初始化
        move['L']=1;
        move['R']=-1;
        move['U']=1;
        move['D']=-1;
        calcu['L']=0;
        calcu['R']=0;
        calcu['D']=0;
        calcu['U']=0;

        for(string::iterator iter=moves.begin();iter!=moves.end();iter++)
        {
            calcu[*iter]+=move[*iter];
        }
        if(calcu['L']+&calcu['R']==0&&calcu['D']+calcu['U']==0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    string moves="RLUURDDDLU";
    Solution sol;
    cout<<sol.judgeCircle(moves)<<endl;
}