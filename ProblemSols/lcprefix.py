class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        mylong = strs[0]
        j = 0
        for i in range(1, len(strs)):
            myprefix = ""
            j = 0
            while(j < len(strs[0]) and j < len(strs[i])):
                if (strs[0][j] == strs[i][j]):
                    myprefix += strs[0][j]
                else:
                    break
                j += 1
            if (len(myprefix) < len(mylong)):
                mylong = myprefix
        return mylong