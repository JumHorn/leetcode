class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        transfer = {}
        state = 0

        for char in p:
            if char == '*':
                transfer[state, char] = state
            else:
                transfer[state, char] = state + 1
                state += 1

        accept = state
        states = {0}

        for char in s:
            states = {transfer.get(
                (at, token)) for at in states if at is not None for token in (char, '*', '?')}

        return accept in states
