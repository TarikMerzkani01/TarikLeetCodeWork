class Solution:
    def reverseWords(self, s: str) -> str:
        def reverseWord(s: str) -> str:
            rev = ""
            for chara in s:
                rev = chara + rev
            return rev
        mylist = s.split(" ")
        newsent = ""
        for i in range(len(mylist)):
            if (i != len(mylist)-1):
                newsent += reverseWord(mylist[i]) + " "
            else:
                newsent += reverseWord(mylist[i])
        return newsent