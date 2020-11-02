class Solution:
    def computeArea(self, A: int, B: int, C: int, D: int, E: int, F: int, G: int, H: int) -> int:
        area1 = (C - A) * (D - B)
        area2 = (G - E) * (H - F)
        intersection = 0
        if E < C and G > A and F < D and H > B:
            intersection = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F))
        return area1 + (area2 - intersection)
