class BattlesshipsinaBoard(object):
    def countBattleships(self,board):
        """
        :type board: List[List[str]]
        :rtype: int
        """
        n=0
        i=0
        while i<len(board):
            j=0
            while j<len(board[0]):
                if board[i][j]=='X':
                    if j+1<len(board[0]) and board[i][j+1]=='X':
                        j+=1
                        while j+1<len(board[0]) and board[i][j+1]=='X':
                            j+=1
                        n+=1
                    else:
                        if i==0:
                            n+=1
                        if i-1>=0 and board[i-1][j]!='X':
                            n+=1
                j+=1
            i+=1
        return n