#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    string longestWord(vector<string>& words) {
        string swap;
        int flag;
        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=words.size()-1;j>i;j--)
            {
                if(words[j].length()<words[j-1].length())
                {
                    swap = words[j];
                    words[j] = words[j-1];
                    words[j-1] = swap;
                }
                else if(words[j].length()==words[j-1].length())
                {
                    if(words[j]>words[j-1])
                    {
                        swap = words[j];
                        words[j] = words[j-1];
                        words[j-1] = swap;
                    }
                }
            }

            if(i>0&&words[i].length()-words[i-1].length()>1)
            {
                flag=i-1;
                break;
            }
            if(i==words.size()-2)
            {
                if(words[i+1].length()-words[i].length()<=1)
                    flag=i+1;
                else
                    flag=i;
            }
        }
        if(flag==0)
        {
            if(words[flag].length()==1)
            {
                return words[flag];
            }
            return "";
        }

        for(int i=flag;i>=0;i--)
        {
            int k=0,j;
            for(j=0;j<words[i].length()-1;j++)
            {
                swap = words[i].substr(0,j+1);
                while(k<i)
                {
                    if(swap==words[k])
                    {
                        break;
                    }
                    k++;
                }
                if(k==i)
                {
                    break;
                }
            }
            if(j==words[i].length()-1)
            {
                return words[i];
            }
        }
        return "";
    }
};