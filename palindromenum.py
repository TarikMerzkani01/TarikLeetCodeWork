class Solution:
    def isPalindrome(self, x: int) -> bool:
        if (x<0):
            return False
        if (x < 10):
            return True
        y = x
        # rem = 0
        # get number of digits first
        numdigs = 0
        while (y > 0):
            y = y // 10
            numdigs += 1
        # numdigs is now the number of digits
        halfdigs = numdigs // 2
        y = x
        z = x
        # travel through digits both ways until reaching half
        dig1 = 0
        dig2 = 0
        mypower = (10 ** (numdigs -1))
        for j in range(halfdigs):
            dig1 = y // (mypower)        #high digit
            y = y % (mypower)
            mypower = mypower // 10
            dig2 = z % 10                #low digit
            z = z // 10
            if (dig1 != dig2):
                return False           
        return True