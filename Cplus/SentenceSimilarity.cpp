#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool areSentencesSimilar(vector<string>& words1, vector<string>& words2, vector<pair<string, string>> pairs) {
        if(words1.size()!=words2.size())
        {
            return false;
        }
        for(int i=0;i<words1.size();i++)
        {
            if(words1[i]==words2[i])
            {
                continue;
            }
            int j;
            for(j=0;j<pairs.size();j++)
            {
                if(pairs[j].first==words1[i])
                {
                    if(pairs[j].second==words2[i])
                    {
                        break;
                    }
                }
                else if(pairs[j].second==words1[i])
                {
                    if(pairs[j].first==words2[i])
                    {
                        break;
                    }
                }
            }
            if(j==pairs.size())
            {
                return false;
            }
        }
        return true;
    }
};