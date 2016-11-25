class bullandCows(object):
    def getHint(self, secret, guess):
        """
        :type secret: str
        :type guess: str
        :rtype: str
        """
        i=0
        j=0
        secret=list(secret)
        guess=list(guess)
        while i<len(secret):
            if secret[i]==guess[i]:
                j+=1
                del secret[i]
                del guess[i]
            else:
                i+=1
        A="%dA"%j
        i=0
        j=0
        while i<len(secret):
            if secret[i] in guess:
                j+=1
                guess.remove(secret[i])
                del secret[i]
            else:
                i+=1
        B="%dB"%j
        return A+B