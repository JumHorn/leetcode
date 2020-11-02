class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows, d = 0, 0, {}
        for i in range(len(secret)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                if d.get(secret[i], 0) < 0:
                    cows += 1
                d[secret[i]] = d.get(secret[i], 0) + 1
                if d.get(guess[i], 0) > 0:
                    cows += 1
                d[guess[i]] = d.get(guess[i], 0) - 1
        res = "%dA%dB" % (bulls, cows)
        return res
