// Each 1 makes 4 perimeters. count total 1s, multiply by 4
// each adjacent 1 removes 2 perimeter, find total adjacents
// Total perimeter = (total 1s * 4) - (total adjacents * 2)
public class Solution {
    public int islandPerimeter(int[][] grid) {
        // count total 1s
        int ones = 0;
        int adj = 0;
        for(int i = 0; i < grid.length; i++)
            for(int j = 0; j < grid[0].length; j++) {
                if(j > 0 && grid[i][j] == grid[i][j-1] && grid[i][j]==1) adj++; // count row adjacent
                if(grid[i][j] == 1) ones++;
            }
        
        // count column adjacents
        for(int j = 0; j < grid[0].length; j++) 
            for(int i = 0; i < grid.length; i++)
                if(i > 0 && grid[i][j] == grid[i-1][j] && grid[i][j]==1) adj++;
                
        return ((ones * 4) - (adj *2));
    }
}