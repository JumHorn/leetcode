#include<vector>
using namespace std;

class NumMatrix {
	vector<vector<int>> *m_matrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
		if(matrix.empty()||matrix[0].empty())
			return;
		int M=matrix.size(),N=matrix[0].size();
		m_matrix=new vector<vector<int>>(M+1,vector<int>(N+1));        
		for(int i=1;i<=M;i++)
			for(int j=1;j<=N;j++)
				(*m_matrix)[i][j]=(*m_matrix)[i][j-1]+(*m_matrix)[i-1][j]-(*m_matrix)[i-1][j-1]+matrix[i-1][j-1];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
    	return (*m_matrix)[row2+1][col2+1]-(*m_matrix)[row2+1][col1]-(*m_matrix)[row1][col2+1]+(*m_matrix)[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
