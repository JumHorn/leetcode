#include<math.h>

double lineDistance(int *p1,int *p2)
{
	double d=(p1[0]-p2[0])*(p1[0]-p2[0])+(p1[1]-p2[1])*(p1[1]-p2[1]);
	return sqrt(d);
}

double triangleArea(int *p1,int *p2,int *p3)
{
	double a=lineDistance(p1,p2);
	double b=lineDistance(p2,p3);
	double c=lineDistance(p3,p1);
	double p=(a+b+c)/2;
	double area=p*(p-a)*(p-b)*(p-c);
	return sqrt(area);
}

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize){
	double res=0.0;
	for(int i=0;i<pointsSize-2;i++)
		for(int j=i+1;j<pointsSize-1;j++)
			for(int k=j+1;k<pointsSize;k++)
			{
				double area=triangleArea(points[i],points[j],points[k]);
				if(area>res)
					res=area;
			}
	return res;
}

