#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
	   	transform(licensePlate.begin(),licensePlate.end(),licensePlate.begin(),::tolower);
		for(string::iterator iter = licensePlate.begin();iter!=licensePlate.end();)
		{
			if(!::isalpha(*iter))
			{
				licensePlate.erase(iter);
				continue;
			}
			iter++;
		}	
		sort(licensePlate.begin(),licensePlate.end());

		bool swap = true;
		int len = words.size();
		while(swap)
		{
			swap = false;
			for(int i=0;i<len-1;i++)
			{
				if(words[i].length()>words[i+1].length())
				{
					string temp;
					temp = words[i];
					words[i] = words[i+1];
					words[i+1] = temp;
					swap = true;
				}
			}
			len--;
		}	

		int index=0;
		while(true)
		{
			if(words[index].length()>=licensePlate.length())
			{
				break;
			}
			index++;
		}

		for(int i = index;i<words.size();i++)
		{
			string wordtemp = words[i];
			sort(wordtemp.begin(),wordtemp.end());
			int j=0,k=0;
			for(int j=0;j<wordtemp.length();j++)
			{
				if(wordtemp[j]==licensePlate[k])
				{
					k++;
					if(k==licensePlate.length())
					{
						return words[i];
					}
				}
			}
		}

		return "";
    }
};
