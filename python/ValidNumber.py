"""
state machine
possible state
0. invalid
1. number
2. number or exponent
3. only number
4. sign
5. point
6. exponent
7. exponent with sign
8. none start

state machine
                            +/-     .       e       number
invalid				0		0		0		0		0
none start			1		5		6		0		2
number				2		0		3		7		2
number and exponent	3		0		0		7		3
only number			4		0		0		0		4
sign				5		0		6		0		2
point				6		0		0		0		3
exponent			7		8		0		0		4
exponent and sign	8		0		0		0		4
"""


class Solution:
    def isNumber(self, s: str) -> bool:
        state = [
            [0, 0, 0, 0],
            [5, 6, 0, 2],
            [0, 3, 7, 2],
            [0, 0, 7, 3],
            [0, 0, 0, 4],
            [0, 6, 0, 2],
            [0, 0, 0, 3],
            [8, 0, 0, 4],
            [0, 0, 0, 4]]
        s = s.strip()
        n = 1  # state start
        for c in s:
            if c == '-' or c == '+':
                n = state[n][0]
            elif c == '.':
                n = state[n][1]
            elif c == 'e':
                n = state[n][2]
            elif c >= '0' and c <= '9':
                n = state[n][3]
            else:
                return False
        return n in (2, 3, 4)  # valid final state
