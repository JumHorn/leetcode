#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> s;
        for(int i=0;i<(int)A.size();i++)
        {
            string tmp(52,'a');
            for(int j=0;j<(int)A[i].length();j++)
                tmp[A[i][j]-'a'+26*(j&1)]++;
            s.insert(tmp);
        }
        return s.size();
    }
};