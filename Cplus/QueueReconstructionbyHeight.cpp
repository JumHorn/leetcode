#include<iostream>
#include<vector>
using namespace std;

// Pick out tallest group of people and sort them in a subarray (S). Since there's no other groups of people taller than them, therefore each guy's index will be just as same as his k value.
// For 2nd tallest group (and the rest), insert each one of them into (S) by k value. So on and so forth.
// E.g.
// input: [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
// subarray after step 1: [[7,0], [7,1]]
// subarray after step 2: [[7,0], [6,1], [7,1]]

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    	for(int i=0;i<static_cast<int>(people.size())-1;i++)
		{
			for(int j=i+1;j<people.size();j++)
			{
				if(people[i].first<people[j].first)
				{
					pair<int,int> temp = people[i];
					people[i] = people[j];
					people[j] = temp;
				}
				else if(people[i].first==people[j].first)
				{
					if(people[i].second>people[j].second)
					{
						pair<int,int> temp = people[i];
						people[i] = people[j];
						people[j] = temp;
					}
				}
			}
		}	

		for(int i=1;i<people.size();i++)
		{
			vector<pair<int, int> >::iterator temp = people.begin();
			people.insert(temp+people[i].second,people[i]);
			people.erase(temp+i+1);
		}

		return people;
    }
};


// time limit exceeded
// class Solution0 {
// public:
//     vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
//     	for(int i=0;i<static_cast<int>(people.size())-1;i++)
// 		{
// 			int n=0;
// 			for(int j=i;j<people.size();j++)
// 			{
// 				int m=0;
// 				for(int k=0;k<i;k++)
// 				{
// 					if(people[k].first>=people[j].first)
// 					{
// 						m++;
// 					}
// 				}
// 				if(people[j].second==m)
// 				{
// 					if(n==0)
// 					{
// 						pair<int,int> temp = people[i];
// 						people[i] = people[j];
// 						people[j] = temp;
// 						n++;
// 					}
// 					else
// 					{
// 						if(people[j].first<people[i].first)
// 						{
// 							pair<int,int> temp = people[i];
// 							people[i] = people[j];
// 							people[j] = temp;
// 						}
// 					}
// 				}
// 			}
// 		}	
// 		return people;
//     }
// };