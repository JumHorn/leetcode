#include<vector>
using namespace std;

struct Grid
{
	char rightnum;		  //the correct number
	char possiblenum[9];   //the possible number
	Grid() : rightnum('0')
	{
		for (int i = 0; i < 9; i++)
		{
			possiblenum[i] = "123456789"[i];
		}
	}
};

class Solution {
private:
	Grid grid[9][9];
	void initzero(int row,int column,int number)
	{
        for (int i = 0; i < 9; i++)
        {
            grid[row][i].possiblenum[number - 1] = '0';
        }
        for (int i = 0; i < 9; i++)
        {
            grid[i][column].possiblenum[number - 1] = '0';
        }
        for (int i = row / 3 * 3; i < 3 + row / 3 * 3; i++)
        {
            for (int j = column / 3 * 3; j < 3 + column / 3 * 3; j++)
            {
                grid[i][j].possiblenum[number - 1] = '0';
            }
        }
        for(int i=0;i<9;i++)
        {
            grid[row][column].possiblenum[i]='0';
        }
	}
    
	int fullinitzero()
	{
        int result = 0;
        //for zero initialization
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j].rightnum == '0')
                {
                    result++;
                }
                else
                {
                    initzero(i, j, grid[i][j].rightnum-'0');
                }
            }
        }

        return result;
	}
    
	int choosing(int row,int column)
	{
        //check self
        int index = 0, flag = 0;
        for (int i = 0; i < 9; i++)
        {
            if (grid[row][column].possiblenum[i] != '0')
            {
                index = i;
                flag++;
                if (flag > 1)
                {
                    break;
                }
            }
        }
        if (flag == 1)
        {
            //self check
            grid[row][column].rightnum = index + 1+'0';
            initzero(row, column, index + 1);
            return 0;
        }

        //check others
        for (int i = 0; i < 9; i++)
        {
            if (grid[row][column].possiblenum[i] != '0')
            {
                int j;
                for (j = 0; j < 9; j++)
                {
                    int k;
                    for (k = 0; k < 9; k++)
                    {
                        if (j != column&&grid[row][j].possiblenum[k] == i + 1+'0')
                        {
                            break;
                        }
                    }
                    if (k != 9)
                    {
                        break;
                    }
                }
                if (j == 9)
                {
                    //row check
                    grid[row][column].rightnum = i + 1+'0';
                    initzero(row, column, i + 1);
                    return 0;
                }
            }
        }

        for (int i = 0; i < 9; i++)
        {
            if (grid[row][column].possiblenum[i] != '0')
            {
                int j;
                for (j = 0; j < 9; j++)
                {
                    int k;
                    for (k = 0; k < 9; k++)
                    {
                        if (j != row&&grid[j][column].possiblenum[k] == i + 1+'0')
                        {
                            break;
                        }
                    }
                    if (k != 9)
                    {
                        break;
                    }
                }
                if (j == 9)
                {
                    //column check
                    grid[row][column].rightnum = i + 1+'0';
                    initzero(row, column, i + 1);
                    return 0;
                }
            }
        }

        for (int l = 0; l < 9; l++)
        {
            if (grid[row][column].possiblenum[l] != '0')
            {
                int i;
                for (i = row / 3 * 3; i < 3 + row / 3 * 3; i++)
                {
                    int j;
                    for (j = column / 3 * 3; j < 3 + column / 3 * 3; j++)
                    {
                        int k;
                        for (k = 0; k < 9; k++)
                        {
                            if ((i != row || j != column) && grid[i][j].possiblenum[k] == l + 1+'0')
                            {
                                break;
                            }
                        }
                        if (k != 9)
                        {
                            break;
                        }
                    }
                    if (j != 3 + column / 3 * 3)
                    {
                        break;
                    }
                }
                if (i == 3 + row / 3 * 3)
                {
                    //grid check
                    grid[row][column].rightnum = l + 1+'0';
                    initzero(row, column, l + 1);
                    return 0;
                }
            }
        }

        return 1;
	}
public:
	int calculate()
	{
        int result = 0;

        //for choosing
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (grid[i][j].rightnum == '0')
                {
                    result += choosing(i, j);
                }
            }
        }
        return result;
	}
    
    void guess()
    {
        guess(0,0);
    }

    bool guess(int i,int j)
    {
        if(i==9)
            return true;
        if(j==9)
            return guess(i+1,0);
        if(grid[i][j].rightnum!='0')
            return guess(i,j+1);

        for(char c='1';c<='9';c++)
        {
            if(guessCheck(i,j,c))
            {
                grid[i][j].rightnum=c;
                if(guess(i,j+1))
                    return true;
                grid[i][j].rightnum='0';
            }
        }
        return false;
    }
    
    bool guessCheck(int i,int j,char val)
    {
        for(int m=0;m<9;m++)
        {
            if(grid[i][m].rightnum==val)return false;
            if(grid[m][j].rightnum==val)return false;
            if(grid[i-i%3+m/3][j-j%3+m%3].rightnum==val)return false;
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char> >& board) {

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if(board[i][j]=='.')
				{
					grid[i][j].rightnum = '0';
					continue;
				}
				grid[i][j].rightnum = board[i][j];
			}
		}
		fullinitzero();

        int result=0;
	    int preresult=0;
		while(true)
        {
            preresult=result;
		    result=calculate();
            if(result==preresult||result==0)
		    {
			    break;
		    }
        }
        if(result!=0)
        {
            guess();
        }

		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				board[i][j] = grid[i][j].rightnum;
			}
		}
    }
};
