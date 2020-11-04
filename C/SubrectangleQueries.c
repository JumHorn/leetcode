#include <stdlib.h>

typedef struct
{
	int updatedRec[500][5];
	int updatedRecSize;
	int **rectangle;
} SubrectangleQueries;

SubrectangleQueries *subrectangleQueriesCreate(int **rectangle, int rectangleSize, int *rectangleColSize)
{
	SubrectangleQueries *res = (SubrectangleQueries *)malloc(sizeof(SubrectangleQueries));
	res->rectangle = rectangle;
	res->updatedRecSize = 0;
	return res;
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries *obj, int row1, int col1, int row2, int col2, int newValue)
{
	obj->updatedRec[obj->updatedRecSize][0] = row1;
	obj->updatedRec[obj->updatedRecSize][1] = col1;
	obj->updatedRec[obj->updatedRecSize][2] = row2;
	obj->updatedRec[obj->updatedRecSize][3] = col2;
	obj->updatedRec[obj->updatedRecSize][4] = newValue;
	++obj->updatedRecSize;
}

int subrectangleQueriesGetValue(SubrectangleQueries *obj, int row, int col)
{
	for (int i = obj->updatedRecSize - 1; i >= 0; --i)
	{
		if (row >= obj->updatedRec[i][0] && row <= obj->updatedRec[i][2] &&
			col >= obj->updatedRec[i][1] && col <= obj->updatedRec[i][3])
			return obj->updatedRec[i][4];
	}
	return obj->rectangle[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries *obj)
{
	if (obj)
		free(obj);
}

/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);

 * int param_2 = subrectangleQueriesGetValue(obj, row, col);

 * subrectangleQueriesFree(obj);
*/