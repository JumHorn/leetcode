#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int> >& ops) {
        if(!ops.size())return m*n;
        int i,j;
        i=(ops[0])[0];
        j=(ops[0])[1];
        // for(vector<vector<int> >::iterator iter=ops.begin()+1;iter!=ops.end();iter++)
        // {
        //     if(*(iter)<i)i=*iter;
        //     if(*(iter+1)<j)j=*(iter+1);
        // }
        for(m=0;m<ops.size();m++)
        {
            if(ops[m][0]<i)i=ops[m][0];
            if(ops[m][1]<j)j=ops[m][1];
        }
        return i*j;
    }
};

int main()
{}