#coding=UTF-8
class ValidSudoku(object):
    def isValidSudoku(self,board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        #set()创建一个集合，集合里面的元素不重复，集合可以实现交并补等运算
        for l in board:
            print l
            if not self.checkrepeat(l):
                return False
        i=0
        while i<9:
            l=[board[0][i],board[1][i],board[2][i],board[3][i],board[4][i],board[5][i],board[6][i],board[7][i],board[8][i]]
            print l
            if not self.checkrepeat(l):
                return False
            i+=1
        i=0
        j=0
        while i<9:
            j=0
            while j<9:
                l=[board[i][j],board[i][j+1],board[i][j+2],board[i+1][j],board[i+1][j+1],board[i+1][j+2],board[i+2][j],board[i+2][j+1],board[i+2][j+2]]
                print l
                if not self.checkrepeat(l):
                    return False
                j+=3
            i+=3  
                  
        return True
        

    def checkrepeat(self,List):
        l=[]
        for n in List:
            if n=='.':
                continue
            if n not in l:
                l.append(n)
            else:
                return False
        return True

V=ValidSudoku()
l=["....5..1.",".4.3.....",".....3..1","8......2.","..2.7....",".15......",".....2...",".2.9.....","..4......"]
V.isValidSudoku(l)