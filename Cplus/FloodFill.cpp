#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>>* image;
    int newColor;
    int originColor;
    int tempcolor;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        this->image = &image;
        this->newColor = newColor;
        this->originColor = image[sr][sc];
        if(originColor==newColor)
        {
            tempcolor = newColor;
            this->newColor=-1;
        }
        paint(sr,sc);
        if(this->newColor==-1)
        {
            for(int i=0;i<image.size();i++)
            {
                for(int j=0;j<image[0].size();j++)
                {
                    if(image[i][j]==-1)
                    {
                        image[i][j]=tempcolor;
                    }
                }
            }
        }
        return image;
    }
    void paint(int r,int c)
    {
        if(r<0||r>=(*image).size()||c<0||c>=(*image)[0].size()||(*image)[r][c]!=originColor)
        {
            return ;
        }
        (*image)[r][c]=newColor;
        paint(r+1,c);
        paint(r-1,c);
        paint(r,c-1);
        paint(r,c+1);
    }
};