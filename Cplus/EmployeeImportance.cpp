#include<iostream>
#include<vector>
using namespace std;

// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

//优化是添加hash键值对提速
class Solution {
public:
    int importance=0;
    int getImportance(vector<Employee*> employees, int id) {
        for(int i=0;i<employees.size();i++)
        {
            if(employees[i]->id==id)
            {
                importance+=employees[i]->importance;
                for(int j=0;j<(employees[i]->subordinates).size();j++)
                {
                    getImportance(employees,(employees[i]->subordinates)[j]);
                }
            }
        }
        return importance;
    }
};