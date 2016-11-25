class RectangleArea(object):
    def computerArea(self,A,B,C,D,E,F,G,H):
        area=(C-A)*(D-B)+(G-E)*(H-F)
        if B>=H or C<=E or F>=D or A>=G:
            return area
        extra=(min(C,G)-max(A,E))*(min(D,H)-max(B,F))
        return area-extra