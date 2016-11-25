#coding=UTF-8
class IslandPerimeter(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        l = len(grid)
        w = len(grid[0])
        print l
        print w
        if l == 1 and w == 1:
            if grid[0][0] == 1:
                return 4
            else:
                return 0
        if l==1:
            i=0
            j=0
            while j<w:
                if grid[0][j]==1:
                    i+=1
                j+=1
            return 4*i-(i-1)*2
        if w==1:
            i=0
            j=0
            while j<l:
                if grid[j][0]==1:
                    i+=1
                j+=1
            return 4*i-(i-1)*2

        i = 1
        j = 1
        m = 0
        while i < l - 1:
            j = 1
            while j < w - 1:
                if grid[i][j] == 1:
                    m = m + 4 - grid[i + 1][j] - grid[i - 1][j] - grid[i][j + 1] - grid[i][j - 1]
                    print m
                j += 1
            i += 1
        j = 1
        while j < w - 1:
            if grid[0][j] == 1:
                m = m + 4 - grid[0][j - 1] - grid[0][j + 1] - grid[1][j]
            if grid[l - 1][j] == 1:
                m = m + 4 - grid[l - 1][j - 1] - grid[l - 1][j + 1] - grid[l - 2][j]
            print m
            j += 1
        i = 1
        while i < l - 1:
            if grid[i][0] == 1:
                m = m + 4 - grid[i - 1][0] - grid[i + 1][0] - grid[i][1]
            if grid[i][w - 1] == 1:
                m = m + 4 - grid[i - 1][w - 1] - grid[i + 1][w - 1] - grid[i][w - 2]
            print m
            i += 1
        if grid[0][0] == 1:
            m = m + 4 - grid[1][0] - grid[0][1]
        if grid[0][w - 1] == 1:
            m = m + 4 - grid[1][w - 1] - grid[0][w - 2]
        if grid[l - 1][0] == 1:
            m = m + 4 - grid[l - 1][1] - grid[l - 2][0]
        if grid[l - 1][w - 1] == 1:
            print l,w
            m = m + 4 - grid[l - 2][w - 1] - grid[l - 1][w - 2]
        return m


I = IslandPerimeter()
# l = [[1,0],[0,0],[0,0]]
# l=[[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
# l = [[1],[0]]
l=[[0,0],[0,1]]
print I.islandPerimeter(l)