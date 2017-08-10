#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string strs[] = {"QWERTYUIOP","ASDFGHJKL","ZXCVBNM"};
        vector<string> key(strs,strs+3);
        map<char,int> keybord;
        //建立map,这是基于string数组
        // int i,j;
        // for(i=0;i<3;i++)
        // {
        //     for(j=0;j<strs[i].length();j++)
        //     {
        //         keybord[strs[i][j]]=i;
        //     }
        // }

        //建立map，基于vector数组
        int i=0;
        for(vector<string>::iterator iter=key.begin();iter!=key.end();iter++,i++)
        {
            for(string::iterator it=iter->begin();it!=iter->end();it++)
            {
                keybord[*it]=i;
            }
        }
        cout<<"keybord created "<<keybord['E']<<keybord['D']<<keybord['V']<<endl;
        //处理words
        for(vector<string>::iterator iter=words.begin();iter!=words.end();)
        {
            if(iter->length()<=1)
            {
                iter++;
                continue;
            }
            string::iterator it;
            //vector<string>::iterator temp;
            for(it=++iter->begin();it!=iter->end();it++)
            {
                //temp=iter;
                if(keybord[toupper(*it)]!=keybord[toupper(*(iter->begin()))])
                {
                    //words.erase(iter++);
                    iter=words.erase(iter);
                    it=iter->begin();
                    break;
                }
            }
            if(it!=iter->begin()&&it==iter->end())
                iter++;
        }
        return words;
    }
};

int main()
{
    Solution sol;
    string strArr[]={"aadsdfghjkla","qwertyuiadfopq","zxadfazm","asadfaedfghjkala","qadfzwertyuiopq","zxcvbnzzm"};
    vector<string> word(strArr,strArr+6);
    vector<string> w=sol.findWords(word);
    for(vector<string>::iterator it=w.begin();it!=w.end();it++)
    {
        cout<<*it<<endl;
    }
    return 0;
}